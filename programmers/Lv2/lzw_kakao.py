def solution(msg):
    answer = []
    d = { chr(i + 65): i+1 for i in range(26) }
    index, i, w = 27, 0, ''
    
    while i < len(msg):
        w += msg[i]
        if w in d: i += 1
        else:
            d[w] = index
            answer.append(d[w[:-1]])
            w, index = '', index+1
        
    answer.append(d[w])
    return answer

print(solution("KAKAO"))
print(solution("TOBEORNOTTOBEORTOBEORNOT"))
