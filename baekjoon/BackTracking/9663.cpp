/* nqueen */
#include <bits/stdc++.h>
using namespace std;
int n, ans = 0;

/* 방법 1

int b[15];
bool isPossible(int x) {
    for (int i = 0; i < x; i++)
        if (b[i] == b[x] || abs(b[x] - b[i]) == x - i)
            return false;
    return true;
}

void nqueen(int x) {
    if (x == n) ans++;
    else {
        for (int i = 0; i < n; i++) {
            b[x] = i;
            if (isPossible(x))
                nqueen(x + 1);
        }
    }
}
*/

bool col[40], diagLeft[40], diagRight[40]; //열과 좌,우측 대각선 검사

void dfs(int x) {
    if(x == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if(col[i] || diagLeft[i+x] || diagRight[x-i+n-1]) continue;
        col[i] = diagLeft[i+x] = diagRight[x-i+n-1] = true;
        dfs(x+1);
        col[i] = diagLeft[i+x] = diagRight[x-i+n-1] = false;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    // nqueen(0);
    dfs(0); 
    cout << ans << "\n";
}