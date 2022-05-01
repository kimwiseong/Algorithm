#include <iostream>
using namespace std;

int n, cnt = 0;
int b[15];

bool isPossible(int x)
{
    for (int i = 0; i < x; i++)
    {
        if (b[i] == b[x] || abs(b[x] - b[i]) == x - i)
            return false;
    }
    return true;
}

void nqueen(int x)
{
    if (x == n)
        cnt++;
    else
    {
        for (int i = 0; i < n; i++)
        {
            b[x] = i;
            if (isPossible(x))
                nqueen(x + 1);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    nqueen(0);
    cout << cnt << "\n";
}