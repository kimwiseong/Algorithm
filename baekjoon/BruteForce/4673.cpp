#include <iostream>
using namespace std;

int d(int n)
{
    int not_self = n;
    while (n != 0)
    {
        not_self += (n % 10);
        n /= 10;
    }
    return not_self;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool isSelf[10001];

    for (int i = 0; i <= 10000; i++)
        isSelf[i] = false;

    for (int i = 1; i <= 10000; i++)
    {
        int num = d(i);
        if (num <= 10000)
            isSelf[num] = true;
        if (!isSelf[i])
            cout << i << "\n";
    }
}