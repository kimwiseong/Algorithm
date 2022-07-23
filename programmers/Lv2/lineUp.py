from math import factorial


def solution(n, k):
    answer, num, k = [], list(range(1, n+1)), k-1
    for i in range(n, 0, -1):
        j, k = divmod(k, factorial(i-1))
        answer.append(num.pop(j))
    return answer

print(solution(5,5))

# factorial을 사용해 permutation갯수(f)를 구하는 것이 풀이
# num의 인덱스 j = k//f
# 자릿수 바꿈  k = k % f