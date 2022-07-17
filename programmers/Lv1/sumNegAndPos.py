def solution(absolutes, signs):
    return sum(i if j else -i for i, j in zip(absolutes, signs))

print(solution([4,7,12], [True, False, True]))