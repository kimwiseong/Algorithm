def solution(n):
    col = [False] * 50; DL = [False] * 50; DR = [False] * 50
    def dfs(x):
        ans = 0
        if x == n: return 1;
        for i in range(n):
            if col[i] or DL[x+i] or DR[x-i+n]: continue
            col[i] = DL[x+i] = DR[x-i+n] = True
            ans += dfs(x+1)
            col[i] = DL[x+i] = DR[x-i+n] = False
        return ans
    return dfs(0)