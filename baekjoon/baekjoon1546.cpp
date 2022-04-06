#include <iostream>
using namespace std;

int main()
{
  int maxScore = 0;
  int score[1000] = {};
  double total = 0, avg = 0;
  int subNum;

  cin >> subNum;
  for (int i = 0; i < subNum; i++)
  {
    cin >> score[i];
    if (score[i] > maxScore)
      maxScore = score[i];
    total += score[i];
  }

  avg = (total / maxScore * 100) / subNum;

  cout << fixed;
  cout.precision(10);
  cout << avg << endl;
}