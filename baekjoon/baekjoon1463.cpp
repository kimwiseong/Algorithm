#include <iostream>
#include <algorithm>
using namespace std;

int dp[1000001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int x;
    cin >> x;

    for (int i = 2; i <= x; i++)
    {
        dp[i] = dp[i - 1] + 1;
        if (i % 2 == 0)
            dp[i] = min(dp[i], dp[i / 2] + 1);
        if (i % 3 == 0)
            dp[i] = min(dp[i], dp[i / 3] + 1);
    }
    cout << dp[x] << "\n";
}