from itertools import combinations_with_replacement
from collections import Counter

def solution(n, info):
    answer, maxDiff = [], -1
    info = info[::-1] 
    
    for cwr in combinations_with_replacement(range(11), n):
        ryan, apeach, tmp = 0, 0, [0]*11
        cnt = Counter(cwr)
        
        for i in range(11):
            if info[i] < cnt[i] : ryan+=i
            elif info[i] != 0: apeach+=i
            tmp[i] = cnt[i]
        if ryan > apeach and maxDiff < ryan - apeach:
            maxDiff, answer = ryan - apeach, tmp
    
    return answer[::-1] if answer else [-1]

print(solution(5, [2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0]))





# maxDiff = 0
# def getScore(info, ryan):
#     s, score = 0, [10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0]
#     for i in range(11):
#         if info[i] > ryan[i]: s -= score[i]
#         elif info[i] < ryan[i]: s += score[i]
#     return s
# def dfs(n, info, ryan, visited, answer):
#     global maxDiff
#     if n == 0:
#         diff = getScore(info, ryan)
#         if diff <= 0: return
#         elif diff >= maxDiff:
#             maxDiff = diff
#             answer.clear()
#             answer.append([_ for _ in ryan])
#         return
#     if n > 0:
#         for i in range(11):
#             if visited[i]: continue
#             visited[i] = True
#             ryan[i] = n if i == len(ryan)-1 else info[i]+1
#             dfs(n-ryan[i], info, ryan, visited, answer)
#             ryan[i], visited[i] = 0, False
# def solution(n, info):
#     answer = []
#     dfs(n, info, [0]*11, [False]*11, answer)
#     if not answer: return [-1]
#     answer.sort(key=lambda x: x[::-1])
#     return answer[-1]