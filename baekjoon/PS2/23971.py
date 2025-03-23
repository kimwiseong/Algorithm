import math

h, w, n, m = map(int, input().split())
print(math.ceil(h/(n+1)) * math.ceil(w/(n+1)))