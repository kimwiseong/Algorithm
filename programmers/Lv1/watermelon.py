def solution(n):
    return "".join(["박" if i % 2 else "수" for i in range(n)])
    
    #다른 사람 풀이
    # return "수박"*(n//2) + "수"*(n % 2)

print(solution(2))