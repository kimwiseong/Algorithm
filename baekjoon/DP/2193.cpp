/** DP, 이친수 */
#include<bits/stdc++.h>
using namespace std;

long long DP[100] = {0, 1, 1};

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 3; i <= n; i++) 
        DP[i] = DP[i-1] + DP[i-2];

    cout << DP[n] << '\n';
}