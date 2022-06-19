def solution(s):
    answer = ''
    tmp = s.split(' ')
    for i in tmp:
        for j in range(len(i)):
            if j % 2 : answer += i[j].lower()
            else: answer += i[j].upper()
        answer += ' '
    return answer[0:-1]
    # return " ".join(map(lambda x: "".join([a.lower() if i % 2 else a.upper() for i, a in enumerate(x)]), s.split(" ")))

print(solution("try hello world"))
