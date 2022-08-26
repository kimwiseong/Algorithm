from collections import deque


def solution(prices):
    answer = []
    prices = deque(prices)
    
    while prices:
        count, price = 0, prices.popleft()
        for i in prices:
            count += 1
            if price > i: break
        answer.append(count)
    return answer

print(solution([1, 2, 3, 2, 3]))
