def solution(numbers, hand):
    answer = ''
    loc = {
        1: [0,0], 2: [0,1], 3: [0,2],
        4: [1,0], 5: [1,1], 6: [1,2],
        7: [2,0], 8: [2,1], 9: [2,2],
        '*':[3,0], 0: [3,1], '#':[3,2]
    }
    l = '*'
    r = '#'
    
    for i in numbers:
        if i in [1, 4, 7]: 
            answer += 'L'
            l = i
        elif i in [3, 6, 9]: 
            answer += 'R'
            r = i
        else:
            dl = abs(loc[l][0] - loc[i][0]) + abs(loc[l][1] - loc[i][1])
            dr = abs(loc[r][0] - loc[i][0]) + abs(loc[r][1] - loc[i][1])
            
            if dr < dl:
                answer += 'R'
                r = i
            elif dr > dl:
                answer += 'L'
                l = i
            else:
                if hand == "right":
                    answer += 'R'
                    r = i
                else:
                    answer += 'L'
                    l = i
                    
    return answer

print(solution([1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5], "right"))