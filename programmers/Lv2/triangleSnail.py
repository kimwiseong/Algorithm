def solution(n):
    answer = [[0]* i for i in range(1, n+1)]
    x, y, num = -1, 0, 1
    
    for i in range(n):
        for _ in range(n-i):
            if i % 3 == 0: x += 1
            elif i % 3 == 1: y += 1
            elif i % 3 == 2: x, y = x-1, y-1
            answer[x][y] = num
            num += 1
    
    return sum(answer, [])

print(solution(4))

