#sqrt(n)을 n**(1/2)로 표현
def solution(n):
    return ((n**(1/2)+1)**2) if n**(1/2) % 1 == 0 else -1

print(solution(3))