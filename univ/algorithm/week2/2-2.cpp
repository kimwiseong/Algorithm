#include <iostream>
using namespace std;

template <typename itemType>
class Stack2 {
public:
    Stack2() {
        head = NULL;
    };
    
    ~Stack2() {
        node* next;
        for(z = head; z != nullptr; z = next) {
            next = z->next;
            delete z;
        }
    };

    void push(itemType const& v) {
        head = new node(v, head);
    };
    
    itemType pop() {
        z = head;
        itemType tmp = z->key;
        head = head->next;
        delete z;
        return tmp;
    };

    int empty() {
        return !head;
    };

private:
    struct node {
        itemType key;
        node *next;
        node(itemType const& key, node* next) : key(key), next(next) {}
    };
    struct node *head, *z;
};

int main() {
    char c; 
    Stack2<int> acc;
    int x;
    int op1, op2;

    while ((c = cin.get()) != '\n') {
        x = 0;
        while (c == ' ') cin.get(c);
        if (c == '+') x = acc.pop() + acc.pop();
        if (c == '*') x = acc.pop() * acc.pop();
        if (c == '-') {
            op1 = acc.pop();
            op2 = acc.pop();
            x = op2 - op1;
        }
        if (c == '/') {
            op1 = acc.pop();
            op2 = acc.pop();
            x = op2 / op1;
        }
        while (c >= '0' && c <= '9') {  
            x = 10 * x + (c - '0');
            cin.get(c);
        }
        acc.push(x);
    }
    cout << acc.pop() << '\n';
}
// 20 30 * 45 3 / + 10 * 9 -