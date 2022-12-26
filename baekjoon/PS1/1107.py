# 1107 - 리모컨

n = int(input())
m = int(input())
remote = { str(i) for i in range(10) }
if m != 0: remote -= set(input().split())

ans = abs(100-n)
for i in range(1000001):
    num = str(i)
    for j in range(len(num)):
        if num[j] not in remote: break
        if j == len(num)-1: ans = min(ans, abs(i - n) + len(num))
print(ans)