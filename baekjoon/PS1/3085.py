#3085 - 사탕 게임(봄보니 게임)

def countCandy(board, n):
    M = 1
    for i in range(n):
        cnt = 1
        for j in range(0, n-1):
            if board[i][j] == board[i][j+1]: cnt+=1
            else: cnt = 1
            M = max(M, cnt)
            
        cnt = 1
        for j in range(0, n-1):
            if board[j][i] == board[j+1][i]: cnt+=1
            else: cnt = 1
            M = max(M, cnt)
        
    return M

n = int(input())
board = [list(input()) for _ in range(n)]
ans = 0

for i in range(n):
    for j in range(n):
        if j < n-1 and board[i][j] != board[i][j+1]: 
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            ans = max((ans, countCandy(board, n)))
            board[i][j], board[i][j+1] = board[i][j+1], board[i][j]
            
        if i < n-1 and board[i][j] != board[i+1][j]:
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
            ans = max((ans, countCandy(board, n)))
            board[i][j], board[i+1][j] = board[i+1][j], board[i][j]
            
print(ans)