/** DP, 재귀, 메모이제이션 */ 
#include<bits/stdc++.h>
using namespace std;

int a, b, c, DP[30][30][30];

int w(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0) 
        return 1;
    
    else if (a > 20 || b > 20 || c > 20) 
        return w(20, 20, 20);
    
    else if (a < b && b < c) 
        if(DP[a][b][c] != 0) return DP[a][b][c]; 
        else return DP[a][b][c] = w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c);
    
    else 
        if (DP[a][b][c] != 0) return DP[a][b][c];
        else return DP[a][b][c] = w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true) {
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << "\n";
    }
}