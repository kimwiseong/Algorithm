def solution(citations):
    answer = 0
    
    for i, c in enumerate(sorted(citations, reverse=True)):
        if i + 1 <= c:
            answer = i + 1
    return answer


print(solution([3, 0, 6, 1, 5]))
