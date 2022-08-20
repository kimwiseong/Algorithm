def solution(n):
    ans = 0
    while(n > 0):
        if n % 2 == 0 : n //= 2
        else: 
            n //= 2
            ans += 1
    return ans
    # return bin(n).count('1')


print(solution(5))
