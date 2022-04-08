#include <iostream>
#include <stack>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int k, n;
    stack<int> s;
    string result = "";
    cin >> k;

    int temp = 1;
    for (int i = 1; i <= k; i++)
    {
        cin << n;
        if (n >= temp)
        {

            while (n != temp)
            {
                s.push(temp++);
                result += "+";
            }
            s.pop();
            result += "-";
        }
        else
        {
            if (s.top() == n)
            {
                s.pop();
                result += "-";
            }
            else
            {
                result = "NO";
                break;
            }
        }
    }
    cout << result << endl;
}