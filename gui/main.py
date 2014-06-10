from connexions import Sock
from gui import Game
import sys

def loop(Sock, Game):
    while True:
        message = s.read().split()
        func = getattr(g, message.pop(0), None)
        if func:
            func(message)
        

if __name__ == '__main__':
    s = Sock(sys.argv[1], sys.argv[2])
    g = Game(s)
    loop(s, g)
