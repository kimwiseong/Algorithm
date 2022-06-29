def solution(dartResult):
    sdt = ['', 'S', 'D', 'T']
    answer = []
    dartResult = dartResult.replace('10', 'k')
    
    for i in dartResult:
        if i == 'k':  answer.append(10)
        elif i in sdt:  answer[-1] **= sdt.index(i)
        elif i == '*':  answer[-2:] = [v*2 for v in answer[-2:]]
        elif i == '#':  answer[-1] *= (-1)
        else:  answer.append(int(i))
    return sum(answer)

print(solution("1S2D*3T"))