def solution(n, left, right):
    return [max(divmod(i,n))+1 for i in range(left, right+1)]

print(solution(3, 2, 5))
