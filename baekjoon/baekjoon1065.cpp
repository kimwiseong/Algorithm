#include <iostream>
using namespace std;

int count_num(int n)
{
    int temp;
    int count = 0;
    int a, b, c;
    for (int i = n; i > 100; i--)
    {
        temp = i;
        a = temp % 10;
        b = temp % 100 / 10;
        c = temp / 100;
        if (c - b == b - a)
            count++;
    }
    return count + 99;
}

int main()
{
    int n, x, count;

    cin >> n;
    if (n > 0 && n < 100)
        cout << n << endl;
    else
        cout << count_num(n) << endl;
}