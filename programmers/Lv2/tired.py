from collections import deque
from itertools import permutations


#bfs 이용
# def solution(k, dungeons):
#     answer = 0
#     dq = deque()
    
#     dq.append([k,[]])
#     while(dq):
#         t, x = dq.popleft()
#         for i, d in enumerate(dungeons):
#             bt, at = d 
#             if i not in x and t >= bt and t - at >= 1: 
#                 dq.append([t-at, x+[i]])
#             else : answer = max(answer, len(x))
#     return answer

#permutations 이용
def solution(k, dungeons): 
    answer = 0
    n = len(dungeons)
    for order in permutations(range(n)):
        cur = k
        ans = 0
        for t in order:
            req, cons = dungeons[t]
            if cur >= req:
                cur -= cons
                ans += 1
            answer = max(ans, answer)
        
    return answer

print(solution(80, [[80,20],[50,40],[30,10]]))