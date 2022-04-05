#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
  int commandNum, inputNum;
  string command;
  stack<int> s;
  int printCommand[10000] = {
      0,
  };
  int index = 0;

  cin >> commandNum;
  if (commandNum < 0 || commandNum > 10000)
  {
    cout << "입력 오류" << endl;
    return 0;
  }

  for (int i = 0; i < commandNum; i++)
  {
    cin >> command;
    if (command == "push")
    {
      cin >> inputNum;
      s.push(inputNum);
    }
    else if (command == "pop")
    {
      if (s.empty())
      {
        printCommand[index] = -1;
      }
      else
      {
        printCommand[index] = s.top();
        s.pop();
      }
      index++;
    }
    else if (command == "size")
    {
      printCommand[index] = s.size();
      index++;
    }
    else if (command == "empty")
    {
      if (s.empty())
      {
        printCommand[index] = 1;
      }
      else
      {
        printCommand[index] = 0;
      }
      index++;
    }
    else if (command == "top")
    {
      if (s.empty())
      {
        printCommand[index] = -1;
      }
      else
      {
        printCommand[index] = s.top();
      }
      index++;
    }
  }

  for (int i = 0; i < index; i++)
  {
    cout << printCommand[i] << endl;
  }

  return 0;
}