def solution(n, lost, reserve):
    ls = set(lost) - set(reserve)
    res = set(reserve) - set(lost)
    for i in res:
        if i-1 in ls: ls.remove(i-1)
        elif i+1 in ls: ls.remove(i+1)
    return n - len(ls)

print(solution(5, [3, 4], [1, 3, 5]))