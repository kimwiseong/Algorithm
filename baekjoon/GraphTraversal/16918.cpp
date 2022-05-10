/* github참고해서 해결, 
 * 이차원배열을 생성하여 폭발시 시간을 체크 
 */
#include <bits/stdc++.h>
using namespace std;

int R, C, N;
int dx[5] = {0, 1, 0, -1};
int dy[5] = {1, 0, -1, 0};
vector<string> board(201);
int cnt[201][201];

bool isPossible(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

void bomb(int t) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (cnt[i][j] == t) {
                for (int k = 0; k < 4; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isPossible(x, y) && cnt[x][y] != t) {
                        board[x][y] = '.';
                        cnt[x][y] = 0;
                    }
                }
                board[i][j] = '.';
                cnt[i][j] = 0;
            }
        }
    }
}

void full(int t) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if(board[i][j] != 'O') {
                board[i][j] = 'O';
                cnt[i][j] = t+3;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C >> N;
    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++)
            if (board[i][j] == 'O')
                cnt[i][j] = 3;
    }

    for (int i = 2; i <= N; i++) {
        if(i%2) bomb(i);
        else full(i);
    }

    for (int i = 0; i < R; i++) 
        cout << board[i] << '\n';
}


/* 
 *맨 처음 작성했던 코드, 시간에 따른 격자판의 상태만 구현했다가 틀림 
 *

int R, C, N;
int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};
bool loc[201][201];
vector<string> board(201);

bool isPossible(int x, int y) {
    return x >= 0 && y >= 0 && x < R && y < C;
}

void bomb() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (loc[i][j]) {
                for (int k = 0; k < 5; k++) {
                    int x = i + dx[k];
                    int y = j + dy[k];
                    if (isPossible(x, y))
                        board[x][y] = '.';
                }
            }
        }
    }
}

void full() {
    for (int i = 0; i < R; i++) 
        for (int j = 0; j < C; j++) 
            board[i][j] = 'O';
}

void init() {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (loc[i][j]) board[i][j] = 'O';
            else board[i][j] = '.';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> R >> C >> N;

    for (int i = 0; i < R; i++) {
        cin >> board[i];
        for (int j = 0; j < C; j++)
            if (board[i][j] == 'O')
                loc[i][j] = true;
    }

    while (true) {
        init();
        N--;
        if (N == 0) break;

        full();
        N--;
        if (N == 0) break;

        bomb();
        N--;
        if (N == 0) break;

        full();
        N--;
        if (N == 0) break;
    }

    for (int i = 0; i < R; i++)
        cout << board[i] << '\n';
}

*/