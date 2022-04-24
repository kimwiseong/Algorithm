// mCn
#include <iostream>

using namespace std;

int dp[30][30];
int c(int m, int n)
{
    if (dp[m][n] > 0)
        return dp[m][n];
    if (m == n || n == 0)
        return 1;
    else
    {
        dp[m][n] = c(m - 1, n - 1) + c(m - 1, n);
        return dp[m][n];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n, m;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << c(m, n) << "\n";
    }
}