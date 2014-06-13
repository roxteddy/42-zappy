from connexions import Sock
from stuff import log

class Game(object):
    teams = {}
    map = {}

    def __init__(self, Sock):
        self.s = Sock

    def welcome(self):
        """
        Send "GRAPHIC" to the server, to start
        the transmission
        """
        self.s.send("GRAPHIC")

    def print_map(self):
        """
        Print map
        """
        for key in self.map:
            print key, self.map[key]

    def orientation(self, o):
        if 0 < o <= 4:
            return True
        return False

    def coordinate(self, x, y):
        if 0 <= x <= self.x and 0 <= y <= self.y:
            return True
        return False


    @classmethod
    def tna(cls, message):
        """
        Create a team if the team does not exist
        """
        if message[0] in cls.teams:
            return log("team %s already exists" % message[0])
        cls.teams[message[0]] = []

    def smg(self, message):
        if message[0]:
            log("server says " + "".join(message))

    def msz(self, message):
        """
        0 = nourriture
        1 = linemate
        2 = deraumere
        3 = sibur
        4 = mendiane
        5 = phiras
        6 = thystame
        """
        try:
            if len(message) != 2:
                raise Exception("wrong parameters")
            self.x = int(message[0])
            self.y = int(message[1])
            if not self.coordinate(self.x, self.y):
                raise Exception("bad coordinates")
        except Exception, e:
            return log(e)
        for i in range(0, self.y):
            self.map[i] = {}
            for j in range(0, self.x):
                self.map[i][j] = []
        log("map x:%d / y:%d created" % (self.x, self.y))
        self.s.send("msz")

    def bct(self, message):
        """
        Create the part of the map[y][x] with a factory
        """
        from object_map import ObjectFactory
        try:
            if len(message) != 9:
                raise Exception("wrong parameters")
            message = tuple([int(integer) for integer in message])
            if not self.coordinate(*message[0:2]):
                raise Exception("bad coordinates: x:%d / y:%d" % (message[0], message[1]))
            x, y, map = message[0], message[1], message[2:]
            if self.map[y][x]:
                del self.map[y][x]
                self.map[y][x] = []
                print self.map[y][x]
            for i in range(0, len(map)):
                if not map[i] in range(0, 2):
                    raise Exception("bad number of object %d" % i)
                elif map[i] == 1:
                    self.map[y][x].append(ObjectFactory(i, x, y))
        except Exception, e:
            return log(e)
        log("Cell %d/%d filled: %s" % (x, y, self.map[y][x]))
        self.s.send("bct " + str(x) + " " + str(y))

    def pbc(self, message):
        try:
            if len(message) != 2:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for team in self.__class__.teams.keys():
            for player in self.__class__.teams[team]:
                if message[0] == player.n:
                    return log("player %d says %s" % (message[0], "".join(message[1:])))
        log("player %d does not exist" % message[0])

    def pex(self, message):
        try:
            if len(message) != 1:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for team in self.__class__.teams.keys():
            for player in self.__class__.teams[team]:
                if message[0] == player.n:
                    self.__class__.teams[team].remove(player)
                    return log("player %d has been kicked" % message[0])
        log("player %d does not exist" % message[0])

    def pdi(self, message):
        try:
            if len(message) != 1:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for team in self.__class__.teams.keys():
            for player in self.__class__.teams[team]:
                if message[0] == player.n:
                    self.__class__.teams[team].remove(player)
                    return log("player %d died" % message[0])
        log("player %d does not exist" % message[0])

    def pnw(self, message):
        """
        Create a new player
        """
        from object_map import Player
        try:
            if len(message) != 6:
                raise Exception("wrong parameters")
            team = message.pop(5)
            if not team in self.__class__.teams:
                raise Exception("team %s does not exist" % team)
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
            if not self.coordinate(*message[1:3]):
                raise Exception("bad coordinates %d / %d" % (message[1], message[2]))
            if not self.orientation(message[3]):
                raise Exception("bad orientation %d" % message[3])
            p = Player(team, *message[0:5])
            for t in self.__class__.teams.keys():
                for player in self.__class__.teams[t]:
                    if p == player:
                        raise Exception("player %d already exists" % p.n)
        except Exception, e:
            return log(e)
        self.__class__.teams[team].append(p)

    def pgt(self, message):
        from object_map import ObjectFactory
        X, Y = -1, -1
        try:
            if len(message) != 2:
                raise Exception("wrong parameters")
            if  message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
        except Exception, e:
            return log(e)
        for t in self.__class__.teams.keys():
            for player in self.__class__.teams[t]:
                if  message[0] == player.n:
                    X, Y = player.X, player.Y
        if X < 0 or Y < 0:
            return log("player %d not found" % message[0])
        removed = ObjectFactory(message[1], X, Y)
        for t in self.map[Y][X]:
            if isinstance(t, type(removed)):
                self.map[Y][X].remove(t)
                return log("player %d took %s" % (message[0], type(t)))
        log("item %s not found on the floor" % (type(removed)))
    
    def pdr(self, message):
        from object_map import ObjectFactory
        try:
            if len(message) != 2:
                raise Exception("wrong parameters")
            if  message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
        except Exception, e:
            return log(e)
        for t in self.__class__.teams.keys():
            for player in self.__class__.teams[t]:
                if  message[0] == player.n:
                    X, Y = player.X, player.Y
        drop = ObjectFactory(message[1], X, Y)
        for t in self.map[Y][X]:
            if isinstance(t, type(drop)):
                return log("object %s already on the floor" % type(drop))
        self.map[Y][X].append(drop)
        return log("player %d dropped %s" % (message[0], type(drop)))
    
    def ppo(self, message):
        try:
            if len(message) != 4:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
        except Exception, e:
            return log(e)
        if not self.coordinate(message[1], message[2]):
            raise Exception("bad coordinates %d / %d" % (message[1], message[2]))
        if not self.orientation(message[3]):
            raise Exception("bad orientation %d" % message[3])
        for t in self.__class__.teams.keys():
            for player in self.__class__.teams[t]:
                if  message[0] == player.n:
                    self.__class__.teams[t][self.__class__.teams[t].index(player)].X = message[1]
                    self.__class__.teams[t][self.__class__.teams[t].index(player)].Y = message[2]
                    self.__class__.teams[t][self.__class__.teams[t].index(player)].O = message[3]
                    return None
        return log("player %d not found" % message[0])

    def plv(self, message):
        try:
            if len(message) != 2:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
        except Exception, e:
            return log(e)
        # if lvl < 0 or lvl > lvlmax
        for t in self.__class__.teams.keys():
            for player in self.__class__.teams[t]:
                if  message[0] == player.n:
                    self.__class__.teams[t][index(player)].L = message[1]
                    return None
        return log("player %d not found" % message[0])

    def enw(self, message):
        """
        Lay an egg by a player at x/y pos
        """
        from object_map import Egg
        try:
            if len(message) != 4:
                raise Exception("wrong parameters")
            if message[1][0] != '#' or message[0][0] != '#':
                raise Exception("bad player number")
            message[1] = message[1][1:]
            message[0] = message[0][1:]
            message = tuple([int(integer) for integer in message])
            e = Egg(*message)
            if not self.coordinate(message[2], message[3]):
                raise Exception("bad coordinates %d / %d" % (message[2], message[3]))
            for i in self.map:
                for x in self.map[i]:
                    for t in self.map[i][x]:
                        if isinstance(t, Egg):
                            raise Exception ("egg %d already exist" % message[0])
            for t in self.__class__.teams.keys():
                for player in self.__class__.teams[t]:
                    if message[1] == player.n:
                        self.map[message[2]][message[3]].append(e)
                        return log("player %d lay the egg %d" % (message[1], message[0]))
            raise Exception("player %d does not exist" % message[1])
        except Exception, e:
            return log(e)

    def eht(self, message):
        from object_map import Egg
        try:
            if len(message) != 1:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for i in self.map:
            for x in self.map[i]:
                for t in self.map[i][x]:
                    if isinstance(t, Egg) and t.e == message[0]:
                        try: 
                            if t.o == 1:
                                raise Exception("egg %d has already hatched out" % message[0])
                            self.map[i][x][self.map[i][x].index(t)].o = 1
                            raise Exception("egg %d has hatched out" % message[0])
                        except Exception, e:
                            return log(e)
        return log("egg %d not found" % message[0])

    def ebo(self, message):
        from object_map import Egg
        try:
            if len(message) != 1:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for i in self.map:
            for x in self.map[i]:
                for t in self.map[i][x]:
                    if isinstance(t, Egg) and message[0] == t.e:
                        try:
                            if t.o == 0:
                                raise Exception("egg %d has not hatched out, player cannot connect on it" % message[0])
                            self.map[i][x].remove(t)
                            raise Exception("egg %d is now a player" % message[0])
                        except Exception, e:
                            return log(e)
        return log("egg %d not found" % message[0])

    def edi(self, message):
        from object_map import Egg
        try:
            if len(message) != 1:
                raise Exception("wrong parameters")
            if message[0][0] != '#':
                raise Exception("bad number")
            message[0] = int(message[0][1:])
        except Exception, e:
            return log(e)
        for i in self.map:
            for x in self.map[i]:
                for t in self.map[i][x]:
                    if isinstance(t, Egg) and message[0] == t.e:
                        try:
                            if t.o == 0:
                                raise Exception("egg %d has not hatched out, it cannot die" % message[0])
                            self.map[i][x].remove(t)
                            raise Exception("egg %d died" % message[0])
                        except Exception, e:
                            return log(e)
        return log("egg %d not found" % message[0])
