#include <iostream>
#include <stack>
#include <string>
using namespace std;

int isPS(string ps)
{
  stack<char> stack;
  for (int i = 0; i < ps.length(); i++)
  {
    if (ps[i] == '(')
      stack.push(ps[i]);
    else
    {
      if (stack.empty())
        return 0;
      stack.pop();
    }
  }
  if (stack.empty())
    return 1;
  else
    return 0;
}

int main()
{
  int t;
  string ps;

  cin >> t;
  int flag[t];
  for (int i = 0; i < t; i++)
  {
    cin >> ps;
    if (ps.length() > 50 || ps.length() < 2)
    {
      cout << "입력 오류" << endl;
      return 0;
    }
    flag[i] = isPS(ps);
  }

  for (int i = 0; i < t; i++)
  {
    if (flag[i] == 1)
      cout << "YES" << endl;
    else if (flag[i] == 0)
      cout << "NO" << endl;
  }
}