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
    int level;
    itemType maxValue, minValue;
public:
    BST() {
        level = 0; maxValue = 0; minValue = 0;
        z = new node(0, infoNIL, 0, 0);
        head = new node(itemMIN, 0, z, z);
    }
    ~BST() {
        delete head;
        delete z;
    }
    void BSTinsert(itemType v, infoType info);
    void findLevel(node* t, int depth);
    void findMax(node* t);
    void findMin(node* t);
    void MaxMinLvl();
};

void BST::BSTinsert(itemType v, infoType info) {
    struct node *p, *x;
    p = head; x = head->r;
    while(x != z) {
        p = x;
        if (v == x->key) return;
        x  = (v < x->key) ? x->l : x->r;
    }
    x = new node(v, info, z, z);
    if (v < p->key) p->l = x;
    else p->r = x;
}

void BST::findLevel(node* t, int depth) {
	if (t == z) return;

	if (level<depth) level = depth;
	if (t->l != z) findLevel(t->l, depth + 1);
	if (t->r != z) findLevel(t->r, depth + 1);
}

void BST::findMax(node* t) {
    if (t == z) return;
    maxValue = t->key;
    findMax(t->r);
}

void BST::findMin(node* t) {
    if (t == z) return;
    minValue = t->key;
    findMin(t->l);
}

void BST::MaxMinLvl() {
	findLevel(head, 1);
    findMax(head);
    findMin(head);
	cout << "최댓값 : " << maxValue << ", 최솟값 : " << minValue << ", 레벨 : " << level << '\n';
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
    t1.MaxMinLvl();
}