def solution(n, arr1, arr2):
    answer = []
    for i in range(n): 
        answer.append(bin(arr1[i] | arr2[i])[2:].zfill(n))
        answer[i] = answer[i].replace('0', ' ')
        answer[i] = answer[i].replace('1', '#')
    return answer

print(solution(6, [46, 33, 33, 22, 31, 50], [27, 56, 19, 14, 14, 10]))