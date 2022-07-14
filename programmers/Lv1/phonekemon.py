def solution(nums):
    return len(set(nums)) if len(nums)//2 >= len(set(nums)) else len(nums)//2
    
    #다른사람 풀이  if-else대신 min사용
    #return min(len(set(nums)), len(nums)//2)

print(solution([3,1,2,3]))