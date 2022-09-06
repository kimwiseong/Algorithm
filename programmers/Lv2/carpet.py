def solution(brown, yellow):
    area = brown+yellow
    
    for x in range(3, brown):
        y = area//x
        if x*y == area and y >= x and yellow == (x-2)*(y-2):
            return [y, x]



print(solution(10, 2))
print(solution(24, 24))