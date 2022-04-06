#include <iostream>
using namespace std;

int main()
{
  int a, b, sum;
  cin >> a >> b;

  if ((a <= 0) || (b > 10) || (a <= 0 && b > 10))
  {
    cout << "입력 오류" << endl;
    return 0;
  }

  sum = a + b;
  cout << sum << endl;
}
