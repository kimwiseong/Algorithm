/*** dfs  */
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph(10001);
bool visited[10001];
int cnt;

void dfs(int x) {
    visited[x] = true;
    cnt++;
    for(const int &next : graph[x])
        if(!visited[next]) dfs(next); 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, A, B; 
    cin >> N >> M;

    while(M--) {
        cin >> A >> B; 
        graph[B].push_back(A);
    }

    vector<int> result;
    int max_cnt = 0;
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        dfs(i);
        memset(visited, false, sizeof(visited));
        if(max_cnt < cnt) {
            max_cnt = cnt;
            result.clear();
            result.push_back(i);
        }
        else if (max_cnt == cnt) 
            result.push_back(i);
    }

    for(const int &i : result) 
        cout << i << ' ';
    cout << '\n';
    return 0;
}