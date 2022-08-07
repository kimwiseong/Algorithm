from math import ceil


def solution(fees, records):
    ptime, total = {}, {}
    
    for record in records:
        time, n, history = record.split() 
        hh, mm = time.split(":")
        if history == "IN" : 
            ptime[n] = int(hh) * 60 + int(mm)
            if n not in total: 
                total[n] = 0 #처음 들어옴
            
        else:
            total[n] += int(hh) * 60 + int(mm) - ptime[n]
            del ptime[n]     #나감

    for k, v in ptime.items():    #key, val, for문
        total[k] += 23*60+59 - v  #나간 기록이 없음
    
    return [fees[1] + ceil((v-fees[0])/fees[2]) * fees[3] if v > fees[0] else fees[1] for k, v in sorted(total.items())]

print(solution([180, 5000, 10, 600], 
            ["05:34 5961 IN", 
            "06:00 0000 IN", 
            "06:34 0000 OUT", 
            "07:59 5961 OUT", 
            "07:59 0148 IN", 
            "18:59 0000 IN", 
            "19:09 0148 OUT", 
            "22:59 5961 IN", 
            "23:00 5961 OUT"]))

# 재입차하는 경우
# 딕셔너리를 삭제하여 처리함!!
# del dict