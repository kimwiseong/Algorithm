#include <iostream>
#include <algorithm>
using namespace std;

int rope[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, result = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> rope[i];

    sort(rope, rope + n);
    for (int i = 0; i < n; i++)
        result = max(result, rope[i] * (n - i));

    cout << result << "\n";
}