def solution(n):
    if n % 2 == 1: return 0
    dp = [1, 0, 3, 0]
    for i in range(4, n+1):
        dp.append((3*dp[i-2]+2*sum([dp[i-j] for j in range(4, n+1, 2) if i-j >= 0])) % 1000000007)
    return dp[n]

print(solution(4))