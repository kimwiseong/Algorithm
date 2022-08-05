def solution(n):
    answer = 1
    
    for i in range(1, n):
        total = 0
        for j in range(i, n):
            total += j
            if total > n: break
            elif total == n: answer += 1
            
    return answer

print(solution(15))