from datetime import date

def solution(a, b):
    w = ["MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"]
    return w[date(2016, a, b).weekday()]

print(solution(5, 24))