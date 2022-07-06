def numOfDivisor(x):
    count=0
    for i in range(1, x+1):
        if x % i == 0: count+=1
    return count % 2;

def solution(left, right):
    answer = 0
    print(numOfDivisor(13))
    for i in range(left, right+1):
        if numOfDivisor(i): answer-=i
        else: answer+=i
    return answer

# 다른 사람이 작성한 코드
# def solution(left, right):
#     answer = 0
#     for i in range(left, right+1):
#         if int(i**0.5) == i**0.5: answer -= i  #제곱수의 약수는 홀수개이므로
#         else: answer += i
#     return answer

print(solution(13, 17))