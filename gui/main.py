from connexions import Sock
from game import Game
from stuff import log

import sys

def loop(s, g):
    while True:
        message = s.read().split()
        if not message:
            continue
        if message[0] == 'BIENVENUE':
            g.welcome()
            continue
        func = getattr(g, message.pop(0), None)
        if func:
            func(message)
        else:
            log("unknown function")
        print g.print_map()
        print g.teams

if __name__ == '__main__':
    if len(sys.argv) != 3:
        log("usage: python main.py host port")
        exit()
    s = Sock(sys.argv[1], sys.argv[2])
    g = Game(s)
    loop(s, g)
