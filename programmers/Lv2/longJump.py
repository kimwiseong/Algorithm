def solution(n):
    DP = [0, 1, 2]
    for i in range(3, n+1) : 
        DP.append((DP[i-1]+DP[i-2])%1234567)
    return DP[n]

print(solution(3))