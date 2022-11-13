#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define infoNIL -1
#define itemMIN 0
#define itemType int
#define infoType int

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
Queue queue;


class BST {
private:
    struct node {
        itemType key; 
        infoType info;
        struct node *l, *r;
        node(itemType k, infoType i, struct node *ll, struct node *rr) {
            key = k; info = i; l = ll; r = rr;
        }
    };
    struct node *head, *z;
    int cnt, size, sum;
public:
    BST() {
        cnt = 0;
        size = 0;
        z = new node(0, infoNIL, 0, 0);
        head = new node(itemMIN, 0, z, z);
    }
    ~BST() {
        delete head;
        delete z;
    }
    infoType BSTsearch(itemType v);
    void BSTinsert(itemType v, infoType info);
    void inorder();
    void inorder(node* t);
    void saveData();
    void saveData(node* t);
    int avgCount();
};

infoType BST::BSTsearch (itemType v) {
    struct node *x = head->r;
    z->key = v;
    while (v != x->key) {
        cnt++;
        x = (v < x->key) ? x->l : x->r;
    }
    return x->info;
}

void BST::BSTinsert(itemType v, infoType info) {
    struct node *p, *x;
    p = head; x = head->r;
    while(x != z) {
        p = x;
        if (v == x->key) return;
        x  = (v < x->key) ? x->l : x->r;
    }
    size++;
    x = new node(v, info, z, z);
    if (v < p->key) p->l = x;
    else p->r = x;
}

void BST::inorder() {
	inorder(head);
}

void BST::inorder(node* t) {
    if (t != z) {
        inorder(t->l);
        BSTsearch(t->key);
        inorder(t->r);
    }
}

void BST::saveData() {
	saveData(head);
}

void BST::saveData(node* t) {
    if (t != z) {
        saveData(t->l);
        cout << t->key << ' ';
        queue.put(t->key);
        saveData(t->r);
    }
}

int BST::avgCount() {
    return cnt/size; 
}

int main() {
    srand(time(NULL));
    BST t1;
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = rand() % n;
        t1.BSTinsert(a, a);
    }

    t1.saveData();
    BST t2;
    while(!queue.empty()) {
        a = queue.get();
        t2.BSTinsert(a, a);
    }
    t2.inorder();
    cout << "\n평균비교회수 : " << t2.avgCount() << '\n';
}