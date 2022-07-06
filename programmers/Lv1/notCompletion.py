import collections

def solution(participant, completion):
    return list((collections.Counter(participant) - collections.Counter(completion)).keys())[0]

print(solution(["mislav", "stanko", "mislav", "ana"], ["stanko", "ana", "mislav"]))