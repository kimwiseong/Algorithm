/**  backtracking , sudoku */
#include<bits/stdc++.h>
using namespace std;
int sudoku[10][10];
bool r[10][10], c[10][10], sq[10][10];

void dfs(int cnt) {
    if(cnt == 81) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++)
                cout << sudoku[i][j] << ' ';
            cout << '\n';
        }
        exit(0);
    }

    int x = cnt / 9;
    int y = cnt % 9;

    if (sudoku[x][y] == 0) {
        for(int i = 1; i <= 9; i++) {
            if (r[x][i] || c[y][i] || sq[(x/3)*3 + (y/3)][i]) continue;
            r[x][i] = c[y][i] = sq[(x/3)*3 + (y/3)][i] = true;
            sudoku[x][y] = i;
            dfs(cnt+1);
            sudoku[x][y] = 0;
            r[x][i] = c[y][i] = sq[(x/3)*3 + (y/3)][i] = false;
            
        }
    }
    else dfs(cnt+1);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for(int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j] != 0)
                r[i][sudoku[i][j]] = c[j][sudoku[i][j]] = sq[(i/3)*3+(j/3)][sudoku[i][j]] = true;
        }
    }
    dfs(0);
}