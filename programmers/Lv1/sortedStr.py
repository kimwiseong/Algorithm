#참고 : https://docs.python.org/ko/3/howto/sorting.html
def solution(strings, n):
    return sorted(sorted(strings), key=lambda x:x[n])

print(solution(["abce", "abcd", "cdx"], 2))