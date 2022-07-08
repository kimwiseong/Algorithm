def solution(answers):
    answer = [0, 0, 0]
    giveUpMan1 = [1, 2, 3, 4, 5]
    giveUpMan2 = [2, 1, 2, 3, 2, 4, 2, 5]
    giveUpMan3 = [3, 3, 1, 1, 2, 2, 4, 4, 5, 5]

    for i, num in enumerate(answers):
        if(giveUpMan1[i%5] == num):
            answer[0] += 1
        if(giveUpMan2[i%8] == num):
            answer[1] += 1
        if(giveUpMan3[i%10] == num):
            answer[2] += 1

    return [i+1 for i, v in enumerate(answer) if v == max(answer)]

print(solution([1, 3, 2, 4, 2]))
