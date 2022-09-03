def solution(number, k):
    answer = [number[0]]
    for num in number:
        while answer and answer[-1] < num and k > 0:
            k -= 1
            answer.pop()
        answer.append(num)
    
    if k > 0: 
        # answer = answer[:len(number)-k]
        answer = answer[:-k]
    return ''.join(answer) 


print(solution("1924", 2))
print(solution("4321", 1))
