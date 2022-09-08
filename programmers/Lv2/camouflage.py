from collections import defaultdict


def solution(clothes):
    answer = 1
    comb = defaultdict(list)
    for name, type in clothes:
        comb[type].append(name)
    
    for k in comb.keys():
        answer *= len(comb[k])+1
    return answer-1


print(solution([["yellow_hat", "headgear"], ["blue_sunglasses", "eyewear"], ["green_turban", "headgear"]]))
