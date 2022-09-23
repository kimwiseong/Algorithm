ttt = int(input())
for _ in range(ttt):
    h, w, n = map(int, input().split(" "))

    num, floor = divmod(n, h)
    floor *= 100
    num += 1

    if floor == 0: print(h*100 + num -1)
    else: print(floor + num)