#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
#define infoNIL -1
#define itemMIN 0
#define itemType int
#define infoType int

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
    int cnt, size;
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
    t1.inorder();
    cout <<"평균비교회수 : "<< t1.avgCount() << '\n';
}