#내가 짠 코드
def solution(n, m):
    def gcd(n, m): return n if m == 0 else gcd(m, n%m)
    return [gcd(n,m), n*m//gcd(n,m)]

#lambda를 사용한 코드
# def solution(n, m):
#     gcd = lambda x, y : x if y == 0 else gcd(y, x%y)
#     lcm = lambda x, y : x*y//gcd(x,y) 
#     return [gcd(n, m), lcm(n, m)]

print(solution(3, 12))