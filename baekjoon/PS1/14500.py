# 14500 - 테트로미노

n, m = map(int, input().split())
board = [list(map(int, input().split())) for _ in range(n)]
ans = 0

case = [
    # block |
    [[0, 0], [0, 1], [0, 2], [0, 3]],
    [[0, 0], [1, 0], [2, 0], [3, 0]],
    # block ㅁ
    [[0, 0], [0, 1], [1, 0], [1, 1]],
    # block L
    [[0, 0], [1, 0], [2, 0], [2, 1]],
    [[0, 0], [1, 0], [0, 1], [0, 2]],
    [[0, 0], [0, 1], [1, 1], [2, 1]],
    [[0, 0], [0, 1], [0, 2], [-1, 2]],
    [[0, 0], [0, 1], [-1, 1], [-2, 1]],
    [[0, 0], [1, 0], [1, 1], [1, 2]],
    [[0, 0], [0, 1], [1, 0], [2, 0]],
    [[0, 0], [0, 1], [0, 2], [1, 2]],
    # block z
    [[0, 0], [1, 0], [1, 1], [2, 1]],
    [[0, 0], [0, 1], [-1, 1], [-1, 2]],
    [[0, 0], [0, 1], [-1, 1], [1, 0]],
    [[0, 0], [0, 1], [1, 1], [1, 2]],
    # block ㅓ
    [[0, 0], [0, 1], [0, 2], [1, 1]],
    [[0, 0], [-1, 1], [0, 1], [1, 1]],
    [[0, 0], [0, 1], [0, 2], [-1, 1]],
    [[0, 0], [1, 0], [2, 0], [1, 1]]
]

def tetromino(x, y): 
    global ans
    for i in range(19):
        total = 0
        for j in range(4):
            try: total += board[x+case[i][j][0]][y+case[i][j][1]]
            except: break
        ans = max(total, ans)

for i in range(n):
    for j in range(m):
        tetromino(i, j)

print(ans)



# def dfs(x, y, cnt, total):
#     global ans
#     global maxNum
    
#     if cnt == 3:
#         ans = max(ans, total)
#         return
#     for i in range(4):
#         nx = x + dx[i]
#         ny = y + dy[i]
#         if 0 <= nx and nx < n and ny <= 0 and ny < m and not visited[nx][ny]:
#             if cnt == 1:
#                 visited[nx][ny] = True
#                 dfs(x, y, cnt+1, total + board[nx][ny])
#                 visited[i][j] = False
#             visited[i][j] = True
#             dfs(nx, ny, cnt+1, total + board[nx][ny])
#             visited[i][j] = False

# n, m = map(int, input().split())
# board = [list(map(int, input().split())) for _ in range(n)]

# dx, dy = (0, 0, 1, -1), (1, -1, 0, 0)
# visited = [[False] * m for _ in range(n)]
# ans = 0
# maxNum = max(board)

# for i in range(n):
#     for j in range(m):
#         visited[i][j] = True
#         dfs(i, j, 0, board[i][j])
#         visited[i][j] = False
# print(ans)