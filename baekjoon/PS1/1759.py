# 1759 - 암호 만들기

def dfs(cnt, x):
    if cnt == l:
        vo, co = 0, 0
        for i in range(l):
            if ans[i] in "aeiou": vo += 1
            else: co += 1
        if vo >= 1 and co >= 2:
            print(''.join(ans))
        return
        
    for i in range(x, c):
        if visited[i]: continue
        ans.append(s[i])
        visited[i] = True
        dfs(cnt+1, i+1)
        visited[i] = False
        del ans[-1]
        
l, c = map(int, input().split())
s = sorted(list(input().split()))
visited = [False] * c
ans = []

dfs(0, 0)