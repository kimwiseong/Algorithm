# DP - 행렬 체인 곱셈 (Matrix Chain Multiplication)
# 참고 - https://doorbw.tistory.com/50
def solution(board):
    answer, x, y = 1, len(board[0])+1, len(board)+1
    dp = [[0] * x  for _ in range(y)]
    
    for i in range(1, y):
        for j in range(1, x):
            if board[i-1][j-1]:
                dp[i][j] = min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])+1
                if dp[i][j] > answer:
                    answer = dp[i][j]

    return answer**2


print(solution([[0, 1, 1, 1], [1, 1, 1, 1], [1, 1, 1, 1], [0, 0, 1, 0]]))


# DP 문제 종류
# 1. 행렬 체인 곱셈 (Matrix Chain Multiplication)
# 2. 거스름 돈 (coin change)
# 3. 배낭 문제 (KnapSack)
# 4. 최장 공통 부분 수열(LCS)
# 5. 최장 증가 부분 수열(LIS)
# 6. 최소 편집 거리 (Edit Distance)

