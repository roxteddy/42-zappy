from connexions import Sock
from stuff import log

class Game(object):
    s, x, y = None, None, None
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
        except Exception, e:
            log(e)
            return None
        if len(message) != 9:
            log("wrong parameters")
            return None
        self.map[message[0]][message[1]] = message[2:]
                
#    def mct(self):
#        for i in range (1, self.y + 1):
#            for j in range (1, self.x + 1):
        
