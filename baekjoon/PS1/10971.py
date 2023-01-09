# 10971 - 외판원 순회2

import sys

def dfs(start, now, value, cnt):
    global ans
    if cnt == n:
        if w[now][start]:
            value += w[now][start]
            ans = min(ans, value)
        return

    if value > ans: return

    for i in range(n):
        if visited[i] or not w[now][i]: continue
        visited[i] = True
        dfs(start, i, value + w[now][i], cnt + 1)
        visited[i] = False

n = int(input())
w = [list(map(int, input().split()))for _ in range(n)]
ans = sys.maxsize
visited = [False] * n

for i in range(n):
    visited[i] = True
    dfs(i, i, 0, 1)
    visited[i] = False
print(ans)


