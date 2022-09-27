#include <iostream>
using namespace std;

class InputNum {
    public:
    InputNum() {
        cout << "Enter number ";
        cin >> _num;
    }

    int GetValue() const { return _num; }

    void SubtractInput() {
        InputNum aNum; 
        _num = _num - aNum.GetValue();
    }

    private:
    int _num;
};

int main() {
    InputNum num;
    cout << "The value is " << num.GetValue() << "\n";
    num.SubtractInput();
    cout << "The value is " << num.GetValue() << "\n";
}