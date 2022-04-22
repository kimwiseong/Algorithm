#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, n;
    cin >> t;
    int DP[40] = {0, 1, 1};

    for (int i = 3; i <= 40; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    while (t--)
    {
        cin >> n;
        if (n == 0)
            cout << 1 << " " << 0 << "\n";
        else if (n == 1)
            cout << 0 << " " << 1 << "\n";
        else
            cout << DP[n - 1] << " " << DP[n] << "\n";
    }
}