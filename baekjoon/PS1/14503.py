# 14503 - 로봇 청소기

def dfs(x, y, d):
    global ans
    if board[x][y] == 0:
        ans += 1
        board[x][y] = 2
    for _ in range(4):
        nd = (d+3) % 4
        nx, ny = x + dx[nd], y + dy[nd]
        if board[nx][ny] == 0:
            dfs(nx, ny, nd)
            return
        d = nd
    nd = (d+2) % 4
    nx, ny = x + dx[nd], y + dy[nd]
    if board[nx][ny] == 1: return
    dfs(nx, ny, d)

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]
n, m = map(int, input().split())
x, y, d = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
visited = [[False] * m for _ in range(n)]
ans = 0

dfs(x, y, d)
print(ans)
