def solution(n, words):
    answer = [words[0][0]]
    for i, w in enumerate(words):
        if w not in answer and answer[-1][-1] == w[0]:
            answer.append(w)
        else: return [i%n+1, i//n+1]
    return [0,0]


print(solution(3, ["tank", "kick", "know", "wheel","land", "dream", "mother", "robot", "tank"]))
