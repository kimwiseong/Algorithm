def solution(a, b):
    return a if a == b else sum(range(a, b+1) if a < b else range(b, a+1))

    #다른 사람의 풀이 : 수열공식 : n(a+l)/2
    #return (abs(a-b)+1)*(a+b)//2
print(solution(3,3))
