# 10973 - 이전 순열

from itertools import permutations

n = int(input())
m = [i for i in range(1, n+1)]

for i in permutations(m):
    print(*i)


