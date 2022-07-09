def solution(N, stages):
    num = len(stages)
    answer = []
    for i in range(1, N+1):
        if num > 0:
            answer.append(stages.count(i)/num)
            num -= stages.count(i)
        else: answer[i] = 0
    return sorted(answer, key=lambda i: answer[i], reverse=True)

print(solution(5, [2, 1, 2, 6, 2, 4, 3, 3]))