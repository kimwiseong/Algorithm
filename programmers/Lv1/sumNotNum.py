def solution(numbers):
    return sum(i for i in range(10) if i not in numbers)

    #다른사람 풀이
    #return 45 - sum(numbers)

print(solution([1,2,3,4,6,7,8,0]))