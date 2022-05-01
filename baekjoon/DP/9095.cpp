#include <iostream>
using namespace std;

int dp[11];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    int t, n;
    for (int i = 4; i < 11; i++)
        dp[i] = dp[i - 3] + dp[i - 2] + dp[i - 1];

    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << dp[n] << "\n";
    }
}