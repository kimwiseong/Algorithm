def solution(arr, divisor):
    arr = sorted([i for i in arr if i % divisor == 0])
    return arr if arr else [-1]
    
    #다른사람 풀이
    #return sorted([i for i in arr if i % divisor == 0]) or [-1]

print(solution([3,2,6], 10))