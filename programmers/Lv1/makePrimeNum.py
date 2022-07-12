from itertools import combinations

def isPrime(x):
    if x < 2: return False
    for i in range(2, int(x**1/2)+1):
        if x % i == 0: return False
    return True

def solution(nums):
    return len([i for i in combinations(nums, 3) if isPrime(sum(i))])

print(solution([1,2,7,6,4]))