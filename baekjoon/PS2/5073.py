while True:
    n1, n2, n3 = map(int, input().split())
    if n1 == n2 == n3 == 0:
        break
    elif (n1 + n2 + n3) - max(n1, n2, n3) * 2 <= 0:
        print("Invalid")
    elif n1 == n2 == n3:
        print("Equilateral")
    elif n1 == n2 or n1 == n3 or n2 == n3:
        print("Isosceles")
    elif n1 != n2 != n3:
        print("Scalene")