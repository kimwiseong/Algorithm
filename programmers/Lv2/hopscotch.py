def solution(land):
    n = len(land)

    for i in range(1, n):
        land[i][0] += max(land[i-1][1], land[i-1][2], land[i-1][3])
        land[i][1] += max(land[i-1][0], land[i-1][2], land[i-1][3])
        land[i][2] += max(land[i-1][0], land[i-1][1], land[i-1][3])
        land[i][3] += max(land[i-1][0], land[i-1][1], land[i-1][2])
    return max(land[n-1])

print(solution([[1, 2, 3, 5], 
                [5, 6, 7, 8], 
                [4, 3, 2, 1]]))

print(solution([[4, 3, 2, 1], 
                [2, 2, 2, 1], 
                [6, 6, 6, 4], 
                [8, 7, 6, 5]]))

# 풀이법 참고
# https://shanepark.tistory.com/183
