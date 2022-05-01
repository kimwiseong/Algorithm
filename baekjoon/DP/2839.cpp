#include <iostream>

using namespace std;
int DP[5000];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    // DP
    //  DP[3] = DP[5] = 1;
    // for (int i = 6; i <= n; i++)
    // {
    //     if (DP[i - 3])
    //         DP[i] = DP[i - 3] + 1;
    //     if (DP[i - 5])
    //         DP[i] = DP[i] ? min(DP[i], DP[i - 5] + 1) : DP[i - 5] + 1;
    // }
    // cout << (DP[n] == 0 ? -1 : DP[n]) << "\n";

    // greedy
    int result = 0;
    while (n >= 0)
    {
        if (n % 5 == 0)
        {
            result += (n / 5);
            cout << result << "\n";
            return 0;
        }
        n -= 3;
        result++;
    }
    cout << -1 << "\n";
}