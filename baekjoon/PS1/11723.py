# 11723 - 집합

import sys
input = sys.stdin.readline

n = int(input())
s = set()

for _ in range(n):
    cmd = input().split()
    
    if len(cmd) == 1:
        if cmd[0] == "all": s = set([x for x in range(1, 21)])
        else: s.clear()
        continue
    
    c, x = cmd[0], int(cmd[1])
    if c == 'add': s.add(x)
    elif c == 'remove':
        if x in s: s.discard(x)
    elif c == 'check': print(int(x in s))
    elif c == 'toggle': 
        if x in s: s.discard(x)
        else: s.add(x)