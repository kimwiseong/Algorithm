#include <iostream>
#include <algorithm>
using namespace std;

int dp[50001] = {0, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + 1;
        for (int j = 2; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
    cout << dp[n] << "\n";
}