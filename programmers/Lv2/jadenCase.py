from string import capwords


def solution(s):
    return capwords(s, ' ')

    #테스트 17에서 실패
    #answer = s[0]
    # s = s.title()
    # if not s[0].isalpha() and s[1].isalpha:
    #     answer+=s[1].lower()
    #     answer+=s[2:]
    # else: answer = s
    # return answer


print(solution("3People unFollowed me"))
print(solution(" for the last week"))
print(solution(" a b"))