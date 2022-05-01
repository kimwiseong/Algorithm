#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    n % 2 == 1 ? cout << "SK\n" : cout << "CY\n";
}