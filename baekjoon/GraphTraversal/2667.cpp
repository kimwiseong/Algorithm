/*** bfs */
#include <bits/stdc++.h>
using namespace std;

int N;
bool board[26][26];
bool visited[26][26];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // right, down, left, up

bool isPossible(int dx, int dy) {
    return (!visited[dx][dy] && dx >= 0 && dy >= 0 && dx < N && dy < N && board[dx][dy]);
}

int bfs(int x, int y) {
    visited[x][y] = true;
    queue<pair<int, int>> q;
    q.push({x, y});
    int cnt = 0;

    while (!q.empty()) {
        cnt++;
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dx = x + dir[i][0];
            int dy = y + dir[i][1];
            if (isPossible(dx, dy)) {
                visited[dx][dy] = true;
                q.push({dx, dy});
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < N; j++)
            board[i][j] = (bool)(s[j] - '0');
    }

    vector<int> result;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(board[i][j] && !visited[i][j])
                result.push_back(bfs(i, j));
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (const int &i : result) cout << i << '\n';
}