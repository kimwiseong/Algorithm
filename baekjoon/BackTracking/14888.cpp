/** backtracking, 최대,최소값을 구하는 연산자 끼워넣기*/
#include<bits/stdc++.h>
using namespace std;
int N, A[20];
int ex[4];      //덧셈, 뺄셈, 곱셈, 나눗셈
int M = -1000000001, m = 1000000001;

void dfs(int x, int v) {
    if(x == N) {
        M = M > v ? M : v;
        m = m > v ? v : m;
    }

    for (int i = 0; i < 4; i++) {
        if(ex[i] == 0) continue;
        ex[i]--;
        if(i == 0) dfs(x+1, v+A[x]);
        else if (i == 1) dfs(x + 1, v-A[x]);
        else if (i == 2) dfs(x + 1, v*A[x]);
        else dfs(x + 1, v/A[x]);
        ex[i]++;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> A[i];
    for(int i = 0; i < 4; i++)
        cin >> ex[i];

    dfs(1, A[0]);
    cout << M << '\n' << m << '\n';
}