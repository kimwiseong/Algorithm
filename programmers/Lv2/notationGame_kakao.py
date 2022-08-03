def trans(num, n):
    notation = '0123456789ABCDEF'
    s = ''
    while True:
        s += notation[num % n]
        num //= n
        if num == 0: break
    return s[::-1]

def solution(n, t, m, p):
    answer = ''
    for i in range(t*m):
        answer += trans(i, n)
    return ''.join(answer[p-1::m][:t])

print(solution(2, 4, 2, 1))
