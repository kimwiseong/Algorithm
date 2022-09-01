def solution(m, n, board):
    answer = 0
    board = list(map(list, board))

    while True:
        remove = []
        flag = True
        
        for i in range(m-1):
            for j in range(n-1):
                if board[i][j] != 0 and board[i][j] == board[i][j+1] == board[i+1][j] == board[i+1][j+1]:
                    remove.append((i,j))
                    remove.append((i,j+1))
                    remove.append((i+1,j))
                    remove.append((i+1,j+1))
                    flag = False
        
        if flag: break
        for i, j in remove:
            board[i][j] = 0

        for i in range(m-1, -1, -1):
            for j in range(n):
                if board[i][j] != 0: continue
                x = i-1
                while x >= 0 and board[x][j]== 0: x -= 1
                
                if x < 0:
                    board[i][j] = 0
                else:
                    board[i][j] = board[x][j]
                    board[x][j] = 0
    
    for b in board:
        answer += b.count(0)
    return answer


print(solution(4, 5, [
    "CCBDE", 
    "AAADE", 
    "AAABF", 
    "CCBBF"]))

print(solution(6, 6, [
    "TTTANT",
    "RRFACC",
    "RRRFCC",
    "TRRRAA",
    "TTMMMF",
    "TMMTTJ"]))

