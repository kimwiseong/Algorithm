/** DP 2xn 타일링(2) */
#include<bits/stdc++.h>
using namespace std;

int n, DP[1100] = { 0, 1, 3 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i = 3; i <= n; i++) 
        DP[i] = (DP[i-1] + DP[i-2]*2) % 10007;
    
    cout << DP[n] << '\n';
}