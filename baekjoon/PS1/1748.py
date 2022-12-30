# 1748 - 수 이어 쓰기 1 - math

n = input()
ans, l = 0, len(n)

for i in range(1, l):
    ans += 9 * 10**(i-1) * i
ans += (int(n) - 10**(l-1) + 1) * l
print(ans)