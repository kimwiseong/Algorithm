def solution(w, h):
    gcd = lambda x, y : x if y == 0 else gcd(y, x%y)
    return w * h - w - h + gcd(w,h)

print(solution(8, 12))
