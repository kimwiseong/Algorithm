#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int DP[90];
    int n;
    cin >> n;
    DP[0] = 0;
    DP[1] = 1;

    for (int i = 2; i <= n; i++)
        DP[i] = DP[i - 1] + DP[i - 2];

    cout << DP[n] << "\n";
}