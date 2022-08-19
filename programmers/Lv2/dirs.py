def solution(dirs):
    answer, x, y = set(), 0, 0
    move = {'U': [0, 1], 'D': [0, -1], 'R': [1, 0], 'L': [-1, 0]}
    
    for i in dirs:
        dx, dy = x+move[i][0], y+move[i][1]
        if not (-5 <= dx <= 5 and -5 <= dy <= 5): continue
        answer.add((x, y, dx, dy))
        answer.add((dx, dy, x, y))
        x, y = dx, dy
        
    return len(answer)//2


print(solution("ULURRDLLU"))
print(solution("LULLLLLLU"))
print(solution("LLLLLLLLLLL"))
print(solution("RRRRRRRRRRR"))
print(solution("UUUUUUUUUUU"))
print(solution("DDDDDDDDDDD"))
