#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#define itemType int
#define infoType int
#define infoNIL 0
#define itemMIN 0
#define black 0
#define red 1
using namespace std;

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
Queue queue; //global queue

class BST {
private:
    struct bnode {
        itemType key; 
        infoType info;
        struct bnode *l, *r;
        bnode(itemType k, infoType i, struct bnode *ll, struct bnode *rr) {
            key = k; info = i; l = ll; r = rr;
        }
    };
    struct bnode *head, *z;
    int cnt, size;

public:
    BST() {
        cnt = size = 0;
        z = new bnode(0, infoNIL, 0, 0);
        head = new bnode(itemMIN, 0, z, z);
    }
    ~BST() { delete head; delete z; }

    infoType BSTsearch (itemType v) {
        struct bnode *x = head->r;
        z->key = v;
        while (v != x->key) {
            cnt++;
            x = (v < x->key) ? x->l : x->r;
        }
        return x->info;
    }
    
    void BSTinsert(itemType v, infoType info) {
        struct bnode *p, *x;
        p = head; x = head->r;
        while(x != z) {
            p = x;
            if (v == x->key) return;
            x  = (v < x->key) ? x->l : x->r;
        }
        size++;
        x = new bnode(v, info, z, z);
        if (v < p->key) p->l = x;
        else p->r = x;
    }

    void inorder() { inorder(head->r); }
    int avgCount() { return cnt / size; }
    int getSize() { return size; }

private:
    void inorder(bnode* t) {
        if (t != z) {
            inorder(t->l);
            cout << t->key << ' '; queue.put(t->key); BSTsearch(t->key);
            inorder(t->r);
        }
    }
};

class RBtree {
private:
    struct node {
        itemType key, tag;
        infoType info;
        struct node *l, *r;
        node(itemType k, infoType i, int tg, struct node *ll, struct node *rr) {
            key = k; info = i; tag = tg; l = ll; r = rr;
        }
    };
    struct node *head, *z, *x, *p, *g, *gg;
    int cnt, size;

public:
    RBtree() {
        z = new node(0, infoNIL, black, 0, 0);
        z->l = z; z->r = z;
        head = new node(itemMIN, 0, black, z, z);
        cnt = size = 0;
    }

    void insert(itemType k, infoType info) {
        x = head; p = head; g = head;
        while (x != z) {
            gg = g; g = p; p = x;
            x = (k < x->key) ? x->l : x->r;
            if (x->l->tag && x->r->tag) split(k);
        }
        x = new node(k, info, 1, z, z);
        if (k < p->key) p->l = x; else p->r = x;
        split(k); 
        head->r->tag = black;
        size++;
    }

    infoType search(itemType v) { 
        struct node *x = head->r;
        z->key = v;
        while (v != x->key) {
            cnt++;
            x = (v < x->key) ? x->l : x->r;
        }
        return x->info;
    }

    void inorder() { inorder(head->r); }

    int avgCount() { return cnt / size; }

    int getSize() { return size; }

private:
    void split(itemType k) {
        x->tag = red; x->l->tag = black; x->r->tag = black;
        if (p->tag) {
            g->tag = red;
            if ((k < g->key) != (k < p->key)) p = rotate(k, g);
            x = rotate(k, gg);
            x->tag = black;
        }
    }

    struct node *rotate(itemType k, struct node* y) {
        struct node *high, *low;
        high = (k < y->key) ? y->l : y->r;
        if (k < high->key) { low = high->l; high->l = low->r; low->r = high; }
        else { low = high->r; high->r = low->l; low->l = high; }
        if (k < y->key) y->l = low; else y->r = low;
        return low;
    }

    void inorder(node* t) {
        if (t != z) {
            inorder(t->l);
            search(t->key);
            inorder(t->r);
        }
    }
};

class Tree234 {
private:
	struct node {
		vector<itemType> value;
		vector<node*> child;

		node(itemType x): value(1, x), child(2) {}
		node(itemType x, node* l, node* r): value(1, x), child(2) {
			child[0] = l; child[1] = r;
		}

		bool split4() {
			if(child.size() != 4) return false;

			node* l = new node(value[0], child[0], child[1]);
			node* r = new node(value[2], child[2], child[3]);

			child.resize(2);
			child[0] = l;
			child[1] = r;

			value[0] = value[1];
			value.resize(1);
			return true;
		}
	};
    node* root; RBtree t3;
public:
	Tree234(): root(nullptr) {}

	bool insert(itemType x) {
		if(!root) {
			root = new node(x);
			return true;
		}
		if(!insert(root, x)) return false;
		return true;
	}

    void ToRedBlack() { inorder(root); }
    int getT3AvgConut() { t3.inorder(); return t3.avgCount(); }

private:
	bool insert(node* cur, itemType x) {
		int i, n = cur->value.size();

		for(i = 0; i < n; ++i) {
			if(x == cur->value[i]) return false;
			if(x < cur->value[i]) break;
		}

		if(node* next = cur->child[i]) {
			if(next->split4()) {
				cur->value.insert(cur->value.begin() + i, next->value[0]);
				cur->child[i] = next->child[0];
				cur->child.insert(cur->child.begin() + i + 1, next->child[1]);
				delete next;

				if(x == cur->value[i]) return false;

				if(x < cur->value[i]) next = cur->child[i];
				else next = cur->child[i + 1];
			}
			return insert(next, x);
		}

		cur->value.insert(cur->value.begin() + i, x);
		cur->child.insert(cur->child.begin() + i, nullptr);
		return true;
	}

    void inorder(node *node) {
        if (!node) return;

        inorder(node->child[0]);
        for (int i = 0; i < node->value.size(); i++) {
            t3.insert(node->value[i], node->value[i]);
            inorder(node->child[i+1]);
        }
    }
};

int main() {
    srand(time(NULL));
    BST t1, t2;
    Tree234 t234;
    
    int n, a;
    cin >> n;
    for (int i = 0; i < n; i++) {
        a = rand() % n;
        t1.BSTinsert(a, a);
    }

    cout << "\nT1 inorder print\n";
    t1.inorder(); //t1 출력 및 각 자료 탐색, 자료 저장 

    while(!queue.empty()) {
        a = queue.get();
        t2.BSTinsert(a, a);
        t234.insert(a);
    }

    t2.inorder();
    t234.ToRedBlack(); //2-3-4 tree -> red-black tree
    
    cout << "\nT1 평균비교회수 : " << t1.avgCount() << '\n';
    cout << "T2 평균비교회수 : " << t2.avgCount() << '\n';
    cout << "T3 평균비교회수 : " << t234.getT3AvgConut() << '\n';
}