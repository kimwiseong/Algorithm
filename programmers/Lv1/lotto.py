def solution(lottos, win_nums):
    rank = [6, 6, 5, 4, 3, 2, 1]
    m = len(lottos) - len(set(win_nums) - set(lottos))
    M = m + lottos.count(0)
    return [rank[M], rank[m]]

print(solution([44, 1, 0, 0, 31, 25], [31, 10, 45, 1, 6, 19]))