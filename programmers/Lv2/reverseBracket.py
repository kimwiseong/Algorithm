from collections import deque

def isVaild(s):
    stack = []
    for b in s:
        if b == '(' or b == '{' or b == '[':
            stack.append(b)
            continue
        if not stack: return False
        tmp = stack.pop()
        if (b == ')' and tmp != '(') or (b == '}' and tmp != '{') or b == ']' and tmp != '[':
            return False
    return len(stack) == 0

def solution(s):
    answer = 0
    s = deque(s)
    
    for _ in range(len(s)):
        s.rotate()
        if isVaild(s): answer+=1
    return answer

print(solution("[](){}"))
print(solution("}]()[{"))
