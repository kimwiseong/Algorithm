#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int commandNum, x;
    string command;
    deque<int> deq;

    cin >> commandNum;

    for (int i = 0; i < commandNum; i++)
    {
        cin >> command;
        if (command == "push_front")
        {
            cin >> x;
            deq.push_front(x);
        }
        else if (command == "push_back")
        {
            cin >> x;
            deq.push_back(x);
        }
        else if (command == "pop_front")
        {
            if (deq.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << deq.front() << endl;
            deq.pop_front();
        }
        else if (command == "pop_back")
        {
            if (deq.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << deq.back() << endl;
            deq.pop_back();
        }
        else if (command == "size")
        {
            cout << deq.size() << endl;
        }
        else if (command == "empty")
        {
            cout << deq.empty() << endl;
        }

        else if (command == "front")
        {
            if (deq.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << deq.front() << endl;
        }

        else if (command == "back")
        {
            if (deq.empty())
            {
                cout << "-1" << endl;
                continue;
            }
            cout << deq.back() << endl;
        }
    }

    return 0;
}