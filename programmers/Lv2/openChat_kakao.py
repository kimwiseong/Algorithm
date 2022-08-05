def solution(record):
    answer = []
    user = {}
    
    for r in record:
        i = r.split()
        if i[0] in ["Enter", "Change"]: user[i[1]] = i[2]
        
    for r in record:
        i = r.split()
        if i[0] == "Enter": answer.append(user[i[1]]+"님이 들어왔습니다.")
        elif i[0] == "Leave": answer.append(user[i[1]]+"님이 나갔습니다.")
        
    return answer


print(solution(
    ["Enter uid1234 Muzi",
    "Enter uid4567 Prodo",
    "Leave uid1234",
    "Enter uid1234 Prodo",
    "Change uid4567 Ryan"]))
