#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    stack<double> s;
    vector<double> v;
    string exp;
    int n;
    double op;
    cin >> n >> exp;

    while (n--)
    {
        cin >> op;
        v.push_back(op);
    }

    for (int i = 0; i < exp.length(); i++)
    {
        double temp = 0;
        if (isalpha(exp[i]))
        {
            s.push(v.at(exp[i] - 65));
        }
        else if (exp[i] == '*')
        {
            temp = s.top();
            s.pop();
            temp *= s.top();
            s.pop();
            s.push(temp);
        }
        else if (exp[i] == '/')
        {
            temp = s.top();
            s.pop();
            temp = s.top() / temp;
            s.pop();
            s.push(temp);
        }
        else if (exp[i] == '+')
        {
            temp = s.top();
            s.pop();
            temp += s.top();
            s.pop();
            s.push(temp);
        }
        else if (exp[i] == '-')
        {
            temp = s.top();
            s.pop();
            temp = s.top() - temp;
            s.pop();
            s.push(temp);
        }
    }
    cout << fixed;
    cout.precision(2);
    cout << s.top() << "\n";
}