#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int F[20];
    F[0] = 0;
    F[1] = 1;
    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
        F[i] = F[i - 1] + F[i - 2];
    cout << F[n] << "\n";
}