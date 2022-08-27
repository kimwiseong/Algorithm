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

# 1(n*3-11)
# 2(n*3-10) 
# 9(n*3-3)
# 3(n*3-9) 
# 10(n*3-2) 
# 8(n*3-4)
# 4(n*3-8), 
# 5(n*3-7), 
# 6(n*3-6), 
# 7(n*3-5)
