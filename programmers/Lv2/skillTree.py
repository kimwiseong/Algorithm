def isValid(st, skill):
    i = 0
    for s in st:
        if s in skill: 
            if s == skill[i]: i+=1
            else: return False
    return True

def solution(skill, skill_trees):
    answer = 0
    for st in skill_trees:
        if isValid(st, skill): answer += 1 
    return answer

print(solution("CBD", ["BACDE", "CBADF", "AECB", "BDA"]))
