def solution(arr):
    answer = []
    for i in range(len(arr)):
        if i == 0: answer.append(arr[i])
        elif arr[i] != arr[i-1]: answer.append(arr[i])
    return answer

print(solution([1,1,3,3,0,1,1]))