def solution(s):
    bracket = []
    for i in s:
        if i == '(' : bracket.append(i)
        else : 
            try: bracket.pop()
            except IndexError : return False
    return len(bracket) == 0

print(solution("()()"))
print(solution(")()("))
print(solution("())()(()"))
