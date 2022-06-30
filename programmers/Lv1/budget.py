def solution(d, budget):
    answer = 0
    for i in sorted(d):
        budget -= i
        if(budget < 0): break;
        answer+=1
    return answer

print(solution([1,3,2,5,4], 9))