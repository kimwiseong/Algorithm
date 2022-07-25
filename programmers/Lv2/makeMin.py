def solution(A,B):
    return sum(i*j for i,j in zip(sorted(A), sorted(B, reverse=True)))
    
print(solution([1,4,2], [5,4,4]))
