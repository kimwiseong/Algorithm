a = 18
cnt = 0

while a > 0:
    if a % 5 == 0:
        cnt += a//5
        break
    cnt += 1
    a -= 3
    
if a < 0: print(-1)
else: print(cnt)