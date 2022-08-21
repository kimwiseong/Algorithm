def solution(arr):
    answer = [0, 0]
    
    def compression(n, x, y):
        v = arr[x][y]
        for i in range(n):
            for j in range(n):
                if arr[x+i][y+j] == v: continue
                compression(n//2, x, y)
                compression(n//2, x+n//2, y)
                compression(n//2, x, y+n//2)
                compression(n//2, x+n//2, y+n//2)
                return
        answer[v] += 1
    
    compression(len(arr), 0, 0)
    return answer

print(solution([[1,1,0,0],
                [1,0,0,0],
                [1,0,0,1],
                [1,1,1,1]]))

print(solution([[1,1,1,1,1,1,1,1],
                [0,1,1,1,1,1,1,1],
                [0,0,0,0,1,1,1,1],
                [0,1,0,0,1,1,1,1],
                [0,0,0,0,0,0,1,1],
                [0,0,0,0,0,0,0,1],
                [0,0,0,0,1,0,0,1],
                [0,0,0,0,1,1,1,1]]))