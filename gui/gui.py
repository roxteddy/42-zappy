from connexions import Sock
from stuff import log

class Player(object):
    def __init__(self, N, n, X, Y, O, L):
        self.n = n
        self.X = X
        self.Y = Y
        self.O = O
        self.L = L
        self.team = N
        log("Player %d created at %d / %d, from %s" % (self.n, self.X, self.Y, self.team))

    def __unicode__(self):
        return "%s: %d" % (self.team, self.n)

    def __repr__(self):
        return unicode(self)

    def __eq__(self, other):
        return self.n == other.n
        
class Game(object):
    teams = {}
    map = {}
    def __init__(self, Sock):
        self.s = Sock

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
        if len(message) != 2:
            log("wrong parameters")
            return None
        try:
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
        if not message[0] in self.map or not message[1] in self.map[message[0]]:
            print self.map
            log("bad coordinates %d/%d" % (message[0], message[1]))
            return None
        self.map[message[0]][message[1]] = message[2:]

    @classmethod
    def tna(cls, message):
        cls.teams[message[0]] = []

    def smg(self, message):
        log("server says" + message)

    def pnw(self, message):
        team = message.pop(5)
        if not team in self.__class__.teams:
            log("team %s does not exist" % team)
            return None
        try:
            if message[0][0] != '#':
                raise Exception("bad player number")
            message[0] = message[0][1:]
            message = tuple(
                [int(integer) for integer in message]
            )
            if len(message) != 5:
                raise Exception("wrong parameters")
            p = Player(team, *message[0:5])
            for t in self.__class__.teams.keys():
                for player in self.__class__.teams[t]:
                    if p == player:
                        raise Exception("player %d already exists" % p.n)
        except Exception, e:
            log(e)
            return None
        self.__class__.teams[team].append(p)

    
