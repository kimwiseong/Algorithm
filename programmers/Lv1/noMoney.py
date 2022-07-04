def solution(price, money, count):
    return count*(price+price*count)//2 - money if count*(price+price*count)//2 > money else 0
    
    # 다른사람 풀이 - 식을 정리하고, max()를 이용하여 0을 처리하였다.
    # return max(0, count*(price+price*count)//2 - money)

print(solution(3, 20, 4))
