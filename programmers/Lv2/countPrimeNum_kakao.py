def trans(n, k):
    s = ''
    while(n):
        s += str(n % k)
        n //= k
    return s[::-1]

def isPrime(x) :
    if x < 2: return False
    for i in range(2, int(x**0.5)+1):
        if x % i == 0: return False
    return True

def solution(n, k):
    s = trans(n, k)    
    answer = 0
    
    for i in s.split('0'):
        if i.isdigit(): 
            if isPrime(int(i)): 
                answer+=1
    return answer

print(solution(437674, 3))
print(solution(110011, 10))
