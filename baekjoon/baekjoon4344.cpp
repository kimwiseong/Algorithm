#include <iostream>
using namespace std;

int main()
{
    int c, n;

    cin >> c;

    for (int i = 0; i < c; i++)
    {
        cin >> n;
        int score[1000], total = 0, count = 0;
        double avg = 0.0;
        for (int j = 0; j < n; j++)
        {
            cin >> score[j];
            total += score[j];
        }

        avg = (double)total / n;
        for (int j = 0; j < n; j++)
        {
            if (score[j] > avg)
                count++;
        }

        cout << fixed;
        cout.precision(3);
        cout << (double)count / n * 100 << "%" << endl;
    }
}