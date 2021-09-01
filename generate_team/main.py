import random
import sys

def gen_team(l, n) :
    for i in range(0, len(l), n) :
        yield l[i:i + n]

def main() :
    if sys.argv[1] == '-h' or sys.argv[1] == '--help' :
        print('py main.py <INPUTFILENAME>')
        return
    members = int(sys.argv[2])
    file = open(sys.argv[1], "r")
    ls = []
    for x in file:
        if x != "\n" :
            ls.append(x.strip('\n'))
    file.close()
    random.shuffle(ls)
    res = list(gen_team(ls, members))
    for i in range(len(res)):
        print(f"Team {i + 1} : {res[i]}")

main()
