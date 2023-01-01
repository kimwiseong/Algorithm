# 14501 - 퇴사 dp

n = int(input())
work = [list(map(int, input().split())) for _ in range(n)] #t, p
dp = [0] * (n+1)

for i in range(n - 1, -1, -1):
    if i + work[i][0] > n: dp[i] = dp[i + 1] #퇴사 이후 일정
    else: dp[i] = max(work[i][1] + dp[i + work[i][0]], dp[i + 1])

print(dp[0])
