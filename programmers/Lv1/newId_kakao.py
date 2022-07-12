def solution(new_id):
    new_id = new_id.lower()
    
    answer = ''
    for i in new_id:
        if i.isalnum() or i in '-_.': answer+=i
        
    while '..' in answer:
        answer = answer.replace('..', '.')
        
    if answer[0] == '.' and len(answer) > 1: answer = answer[1:]
    if answer[-1] == '.': answer = answer[:-1]
    
    if answer == '': answer = 'a'
    
    if len(answer) >= 16: 
        answer = answer[:15]
        if answer[-1] == '.': answer = answer[:-1]
    
    if len(answer) <= 2:
        answer += answer[-1]*(3-len(answer))
    
    return answer

print(solution("...!@BaT#*..y.abcdefghijklm"))