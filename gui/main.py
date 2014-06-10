from connexions import Sock
import sys

def loop(Sock, Game):
    while True:
        message = s.read().split()
        getattr(g, message.pop(0))(message)

if __name__ == '__main__':
    s = Sock(sys.argv[1], sys.argv[2])
    g = Game(s)
    loop(s, g)
