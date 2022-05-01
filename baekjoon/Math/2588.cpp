#include <iostream>
using namespace std;

int main()
{
  int a, b, c, d, e;

  cin >> a >> b;
  if (a < 100 || a >= 1000 || b < 100 || b >= 1000)
  {
    cout << "입력 오류" << endl;
    return 0;
  }
  c = b % 10;
  d = b % 100 / 10;
  e = b / 100;

  cout << a * c << endl
       << a * d << endl
       << a * e << endl
       << a * b << endl;
}