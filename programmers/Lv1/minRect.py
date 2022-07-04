def solution(sizes):
    M = []
    m = []
    for i in sizes:
        M.append(max(i))
        m.append(min(i))
    return max(M) * max(m)

    #다른 사람 풀이
    #return max(max(i) for i in sizes) * max(min(i) for i in sizes)


print(solution([[14, 4], [19, 6], [6, 16], [18, 7], [7, 11]]))
