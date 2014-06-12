from stuff import log
from gui import Game

class Entity(object):
    def __init__(self, X, Y):
        self.X = X
        self.Y = Y

    def __unicode__(self):
        return "%s: %d/%d" % (self.__class__.__name__, self.X, self.Y)

    def __repr__(self):
        return unicode(self)

    def remove_from_map(self):
        Game.map[self.Y][self.X].remove(self)

class Food(Entity):
    def __init__(self, X, Y):
        super(Food, self).__init__(X, Y)

class Linemate(Entity):
    def __init__(self, X, Y):
        super(Linemate, self).__init__(X, Y)

class Deraumere(Entity):
    def __init__(self, X, Y):
        super(Deraumere, self).__init__(X, Y)

class Sibur(Entity):
    def __init__(self, X, Y):
        super(Sibur, self).__init__(X, Y)

class Mendiane(Entity):
    def __init__(self, X, Y):
        super(Mendiane, self).__init__(X, Y)

class Phiras(Entity):
    def __init__(self, X, Y):
        super(Phiras, self).__init__(X, Y)

class Thystame(Entity):
    def __init__(self, X, Y):
        super(Thystame, self).__init__(X, Y)

class Egg(Entity):
    def __init__(self, e, n, X, Y, d = 0, o = 0):
        """
        d = mort ? 0 = non, 1 = oui
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

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        return self.e == other.e

class Player(Entity):
    def __init__(self, N, n, X, Y, O, L):
        super(Player, self).__init__(X, Y)
        self.n = n
        self.O = O
        self.L = L
        self.team = N
        log("Player %d created at %d / %d, from %s" % (self.n, self.X, self.Y, self.team))

    def __eq__(self, other):
        return self.n == other.n


class ObjectFactory(object):
    objects = {
        0: Food,
        1: Linemate,
        2: Deraumere,
        3: Sibur,
        4: Mendiane,
        5: Phiras,
        6: Thystame,
    }

    def __new__(cls, n, *args, **kwargs):
        return ObjectFactory.objects[n](*args, **kwargs)
