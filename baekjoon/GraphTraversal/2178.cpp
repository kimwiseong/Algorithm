/*** bfs, 미로찾기 */
#include <bits/stdc++.h>
using namespace std;

int N, M;
int dist[101][101];
bool board[101][101];
bool visited[101][101];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} }; //right, down, left, up

bool isPossible(int dx, int dy) {
    return (!visited[dx][dy] && dx >= 0 && dy >= 0 && dx < N  && dy < M && board[dx][dy] && dist[dx][dy] == 0);
}

void bfs(int x, int y) {
    visited[x][y] = true;
    dist[x][y] = 1;
    queue<pair<int, int>> q;
    q.push({x, y});

    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if(isPossible(dx, dy)) {
                visited[dx][dy] = true;
                q.push({dx, dy});
                dist[dx][dy] = dist[x][y] + 1;
            }
        } 
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        for (int j = 0; j < M; j++) {
            board[i][j] = (bool)(s[j] - '0');
        }
    }
    
    bfs(0,0);
    cout << dist[N-1][M-1] << "\n";
}