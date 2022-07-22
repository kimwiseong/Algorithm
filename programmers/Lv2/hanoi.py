def solution(n):
    answer = []
    
    def hanoi(x, s, t, e):
        if x == 0: return
        hanoi(x-1, s, e, t)
        answer.append([s, e])
        hanoi(x-1, t, s, e)
        
    hanoi(n, 1, 2, 3)
    return answer

print(solution(2))