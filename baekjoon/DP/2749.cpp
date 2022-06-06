/** DP, 피보나치, 피사노 주기 */
#include<bits/stdc++.h>
using namespace std;

int DP[1500000] = {0, 1, 1};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    long long int n; 
    cin >> n;
    for (int i = 3; i <= n%1500000; i++)
        DP[i] = (DP[i-1] + DP[i-2]) % 1000000;
    cout << DP[n % 1500000] << '\n';
}