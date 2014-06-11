from connexions import Sock
from stuff import log

class Entity(object):
    def __init__(self, X, Y):
        self.X = X
        self.Y = Y

    def __repr__(self):
        return unicode(self)

class Egg(Entity):
    def __init__(self, o, e, n, X, Y):
        """
        o = eclot ? 0 = non, 1 = oui
        e = numero de l'oeuf
        n = numero du joueur qui a pondu
        X = coordonnee X
        Y = coordonnee Y
        """
        super(Egg, self).__init__(X, Y)
        self.o = o
        self.e = e
        self.n = n
        log("Egg %d created at %d / %d from player %d" % (self.e, self.X, self.Y, self.n))

    def __unicode__(self):
        return "%s: %d" % (self.team, self.n)

    def __eq__(self, other):
        return self.e == other.e

class Player(Entity):
    def __init__(self, N, n, X, Y, O, L):
        super(Player, self).__init__(X, Y)
        self.n = n
        self.O = O
        self.L = L
        self.team = N
        log("Player %d created at %d / %d, from %s" % (self.n, self.X, self.Y, self.team))

    def __unicode__(self):
        return "%s: %d" % (self.team, self.n)

    def __eq__(self, other):
        return self.n == other.n
        
class Game(object):
    teams = {}
    map = {}
    eggs = []
    def __init__(self, Sock):
        self.s = Sock

    def coordinate(self, x, y, o = None):
        if x > self.x or y > self.y or (o is not None and (o > 4 or o <= 0)) or x <= 0 or y <= 0:
            return False
        else:
            return True

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
        except Exception, e:
            log(e)
            return None
        for i in range(1, self.y + 1):
            self.map[i] = {}
            for j in range(1, self.x + 1):
                self.map[i][j] = (0, 0, 0, 0, 0, 0, 0)

    def bct(self, message):
        try:
            message = tuple(
                [int(integer) for integer in message]
            )
            if len(message) != 9:
                raise Exception("wrong parameters")
        except Exception, e:
            log(e)
            return None
        if not self.coordinate(*message[0:1]):
            log("bad coordinates %d/%d" % (message[0], message[1]))
            return None
        self.map[message[0]][message[1]] = message[2:]

    @classmethod
    def tna(cls, message):
        if message[0] in cls.teams:
            log("team %s already exists" % message[0])
            return None
        cls.teams[message[0]] = []

    def enw(self, message):
        try:
            if len(message) != 4:
                raise Exception("wrong parameters")
            if message[1][0] != '#' or message[0][0] != '#':
                raise Exception("bad player number")
            message[1] = message[1][1:]
            message[0] = message[0][1:]
            message = tuple(
                [int(integer) for integer in message]
            )
            e = Egg(0, *message)
            if not self.coordinate(message[2], message[3]):
                raise Exception("bad coordinates %d / %d" % (message[2], message[3]))
            for egg in self.eggs:
                if e == egg:
                    raise Exception("bad egg number (already exists)")
                    return None
            for t in self.__class__.teams.keys():
                for player in self.__class__.teams[t]:
                    if message[1] == player.n:
                        self.eggs.append(e)
                        return None
            raise Exception("player %d does not exist" % message[1])
        except Exception, e:
            log(e)
            return None

    def smg(self, message):
        log("server says " + message[0])

    def pnw(self, message):
        try:
            if len(message) != 6:
                raise Exception("wrong parameters")
            team = message.pop(5)
            if not team in self.__class__.teams:
                raise Exception("team %s does not exist" % team)
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple(
                [int(integer) for integer in message]
            )
            if not self.coordinate(*message[1:3]):
                raise Exception("bad coordinates %d / %d / %d" % (message[1], message[2], message[3]))
            p = Player(team, *message[0:5])
            for t in self.__class__.teams.keys():
                for player in self.__class__.teams[t]:
                    if p == player:
                        raise Exception("player %d already exists" % p.n)
        except Exception, e:
            log(e)
            return None
        self.__class__.teams[team].append(p)

    
