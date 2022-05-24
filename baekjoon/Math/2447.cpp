/* 프렉탈, 재귀 - 좌표 이용, 빈칸 or 별 출력 */

#include<bits/stdc++.h>
using namespace std;
int N; 

void solve(int i, int j, int N) {
    if((i/N) % 3 == 1 && (j/N) % 3 == 1) 
        cout << ' ';
    else {
        if(N/3 == 0) cout << '*';
        else solve(i, j, N/3);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) 
            solve(i, j, N);
        cout << '\n';
    }
}
