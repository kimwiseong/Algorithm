def solution(s):
    i, countZero = 0, 0
    
    while s != '1':
        countZero += s.count('0')
        s = bin(len(s.replace('0','')))[2:]
        i+=1
    return [i, countZero]


print(solution("110010101001"))
