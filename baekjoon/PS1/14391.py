# 14391 - 종이 조각

def bitmask():
    ans = 0
    for i in range(1 << n * m):
        total = 0
        
        for r in range(n):
            rowSum = 0
            for c in range(m):
                idx = r * m + c
                if i & (1 << idx) != 0: rowSum = rowSum * 10 + paper[r][c]
                else: total, rowSum = total+rowSum, 0
            total += rowSum
        
        for c in range(m):
            colSum = 0
            for r in range(n):
                idx = r * m + c
                if i & (1 << idx) == 0: colSum = colSum * 10 + paper[r][c]
                else: total, colSum = total + colSum, 0
            total += colSum
        
        ans = max(ans, total)
    return ans

n, m = map(int, input().split())
paper = [list(map(int, input())) for _ in range(n)]
print(bitmask())