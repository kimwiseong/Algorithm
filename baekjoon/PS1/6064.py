# 6064 - 카잉 달력 - math

def calendar(m, n, x, y):
    while m * n >= x:
        if (x - y) % n == 0:
            return x
        x += m
    return -1

t = int(input())
for i in range(t):
    m, n, x, y = (map(int, input().split()))
    print(calendar(m, n, x, y))