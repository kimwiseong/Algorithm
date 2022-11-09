#include <iostream>
using namespace std;

struct node {
    char info;
    struct node *l, *r;
    ~node() { l = NULL, r = NULL; }
};
struct node *x, *z;

template <typename itemType>
class Stack {
private:
    struct snode {
        itemType key;
        struct snode *next;
        snode(itemType key, snode* next) : key(key), next(next) {};
    };
    struct snode *head, *z;

public:
    Stack() { head = NULL; }
    
    ~Stack() {
        snode* tmp;
        for(z = head; z != nullptr; z = tmp) {
            tmp = z->next;
            delete z;
        }
    }

    void push(itemType v) { head = new snode(v, head); }
    
    itemType pop() {
        if (empty()) return 0;
        z = head;
        itemType v = z->key;
        head = head->next;
        delete z;
        return v;
    };
    
    bool empty() { return !head; };
};


template <typename itemType>
class Queue {
private:
    struct qnode {
        itemType key;
        struct qnode *next;
        qnode(itemType key) : key(key), next(NULL) {};
    };

    struct qnode *head, *tail;
public:
    Queue() { head = tail = NULL; }
    ~Queue() {delete head; }

    void put(itemType v) {
        struct qnode *tmp = new qnode(v);

        if (head == NULL) {
            head = tail = tmp;
            tail->next = head;
        }
        else {
            tail->next = tmp;
            tail = tmp;
            tail->next = head;
        }
    }

    itemType get() {

        itemType v;
        if (head == tail) {
            v = head->key;
            head = NULL;
            tail = NULL;
        }

        else {
            struct qnode* tmp = head;
            v = tmp->key;
            head = head->next;
            tail->next = head;
            free(tmp);
        }
        return v;
    }

    bool empty() {
        return head == NULL && tail == NULL;
    }
};



void visit(struct node *t) {
    cout << t->info << ' ';
}

void levelOrderTraverse(struct node *t) {
    cout << "level order : ";
    Queue<node *> queue;
    queue.put(t);
    
    while (!queue.empty()) {
        t = queue.get(); 
        visit(t);
        if (t->l != z) queue.put(t->l);
        if (t->r != z) queue.put(t->r);
    }
}


int main() {
    char c; 
    Stack<node *> stack;

    z = new node; z->l = z; z->r = z;
    while((c = cin.get()) != '\n') {
        while(c == ' ') cin.get(c);
        x = new node;
        x->info = c; x->l = z; x->r = z;
        if (c == '+' || c == '*') {
            x->r = stack.pop(); x->l = stack.pop();
        }
        stack.push(x);
    }

    levelOrderTraverse(stack.pop());
    cout << '\n';
}

// A B C + D E * * F + *