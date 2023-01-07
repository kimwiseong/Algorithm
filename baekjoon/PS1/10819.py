#10819 - 순열

from itertools import permutations

n = int(input())
m = list(map(int, input().split()))
ans = 0

for i in permutations(m):
    tmp = 0
    for j in range(len(i)-1):
        tmp += abs(i[j]-i[j+1])
    ans = max(ans, tmp)

print(ans)