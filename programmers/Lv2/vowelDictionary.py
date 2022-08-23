from itertools import product

def solution(word):

    dict = [''.join(j) for i in range(1, 6) for j in product(['A', 'E', 'I', 'O', 'U'], repeat = i)]
    return sorted(dict).index(word)+1


print(solution("AAAAE"))

