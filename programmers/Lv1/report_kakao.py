def solution(id_list, report, k):
    answer = [0] * len(id_list)
    report = [i.split() for i in set(report)]
    countR = {x:0 for x in id_list}

    for i in report: countR[i[1]] += 1
    for i in report:
        if countR[i[1]] >= k: answer[id_list.index(i[0])] += 1
    return answer

print(solution(["muzi", "frodo", "apeach", "neo"], ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"], 2))