def solution(arr):
    gcd = lambda x, y : x if y == 0 else gcd(y, x%y)
    lcm = lambda x, y : x*y//gcd(x,y)
    while len(arr) != 1: arr.append(lcm(arr.pop(), arr.pop()))
    return arr[0]

print(solution([2, 4, 6, 8]))