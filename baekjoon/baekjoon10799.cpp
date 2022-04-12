#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> p;
    int sum = 0;
    bool isPair;
    string b;

    cin >> b;
    for (int i = 0; i < b.length(); i++)
    {
        if (b[i] == '(')
        {
            p.push(b[i]);
            isPair = true;
        }
        else if (b[i] == ')' && isPair)
        {
            p.pop();
            sum += p.size();
            isPair = false;
        }
        else if (b[i] == ')' && !isPair)
        {
            p.pop();
            sum += 1;
        }
    }
    cout << sum << "\n";
}