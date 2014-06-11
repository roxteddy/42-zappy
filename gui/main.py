from connexions import Sock
from gui import Game
import sys

def loop(s, g):
    while True:
        message = s.read().split()
        func = getattr(g, message.pop(0), None)
        if func:
            func(message)

if __name__ == '__main__':
    if len(sys.argv) != 3:
        log("usage: python main.py host port")
        exit()
    s = Sock(sys.argv[1], sys.argv[2])
    g = Game(s)
    loop(s, g)
