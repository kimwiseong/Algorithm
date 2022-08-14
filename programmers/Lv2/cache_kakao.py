from collections import deque

def dequeSolution(cacheSize, cities):
    cache = deque(maxlen=cacheSize)
    answer = 0
    for city in cities:
        city = city.lower()
        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
        else: 
            answer += 5
            cache.append(city)
    return answer


def solution(cacheSize, cities):
    answer = 0
    cache = []
    for city in cities:
        city = city.lower()
        
        if city in cache:
            answer += 1
            cache.remove(city)
            cache.append(city)
        
        else:
            answer += 5
            if len(cache) < cacheSize: 
                cache.append(city)
            else:
                try: 
                    cache.pop(0)
                    cache.append(city)
                except IndexError: continue
        
            
    return answer

print(solution(3, ["Jeju", "Pangyo", "Seoul", "NewYork","LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
print(solution(2, ["Jeju", "Pangyo", "NewYork", "newyork"]))
print(solution(0, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
print()
print(dequeSolution(3, ["Jeju", "Pangyo", "Seoul", "NewYork","LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
print(dequeSolution(0, ["Jeju", "Pangyo", "Seoul", "NewYork", "LA"]))
