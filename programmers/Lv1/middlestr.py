def solution(s):
    l = len(s)//2
    return s[l] if len(s) % 2 else s[l-1:l+1]
    
    #다른 사람 풀이
    #return s[(len(s)-1)//2:len(s)//2+1]   
print(solution("abcd"))
