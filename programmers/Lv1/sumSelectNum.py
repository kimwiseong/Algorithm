def solution(numbers):
    answer = []
    for i in numbers:
        for j in range(numbers.index(i)+1, len(numbers)):
            answer.append(i+numbers[j])
    return sorted(set(answer))

    #다른 사람 풀이 : combinations를 활용하는 방법도 있다.
    #return sorted(set(sum(i) for i in list(combinations(numbers, 2))))
    
print(solution([2,1,3,4,1]))