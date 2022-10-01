#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

template <typename T>
class Stack {
    private:
    struct node {
        T key;
        node *next;
        node(T const& key, node* next) : key(key), next(next) {}
    };
    struct node *head, *z;
    public:
    Stack() { head = NULL; };
    
    ~Stack() {
        node* tmp;
        for(z = head; z != nullptr; z = tmp) {
            tmp = z->next;
            delete z;
        }
    };

    void push(T const& v) { head = new node(v, head); };
    
    T pop() {
        if (empty()) return NULL;
        z = head;
        T v = z->key;
        head = head->next;
        delete z;
        return v;
    };

    T top() const {
        if (head == NULL) return NULL;
        return head->key;
    }
    
    bool empty() { return head == NULL; };
};

template <typename itemType>
class Set {
    private:
    struct bst {
        itemType data;
        struct bst *left, *right; 
        bst(itemType const& data) : data(data), left(NULL), right(NULL){}
        ~bst() { left = NULL; right = NULL; }
    };
    struct bst *root, *tmp;

    bst* insertBst(bst* node, itemType data) {
	if (empty(node)) 
            return new bst(data);

	if (data < node->data) 
	    node->left = insertBst(node->left, data);
	else if (data > node->data) 
            node->right = insertBst(node->right, data);

	return node;
    }

    void inorder(bst* node) {
	if (empty(node)) return;
	inorder(node->left);
	cout << node->data << " ";
	inorder(node->right);
    }

    bool containsBst(bst* node, itemType data) {
	if (empty(node))  return false;
	return node->data == data || containsBst(node->left, data) || containsBst(node->right, data);
    }

    bool empty(bst* node) { return !node; }

    public:
    Set() { root = NULL; }
    ~Set() { delete root; }

    void insert(int data) {
	if (!containsBst(root, data)) 
            root = insertBst(root, data);
    }

    void printUnion(Set& s) {
	Set<int> u;
	if (root == NULL) return s.printSet();
	if (s.root == NULL) return printSet();

	Stack<bst*> stack;
	stack.push(root);
	while (!stack.empty()) {
	    tmp = stack.pop();

	    u.insert(tmp->data);
	    if (tmp->right) stack.push(tmp->right);
	    if (tmp->left) stack.push(tmp->left);
	}

	stack.push(s.root);
	while (!stack.empty()) {
	    tmp = stack.pop();

    	    u.insert(tmp->data);
	    if (tmp->right) stack.push(tmp->right);
	    if (tmp->left) stack.push(tmp->left);
	}
	u.printSet();
    }

    void printIntersection(Set& s) {
	Set<int> x;
	Stack<bst*> stack;
	stack.push(root); 

	while (!stack.empty()) {
            tmp = stack.pop();

   	    if (s.contains(tmp->data)) x.insert(tmp->data);
	    if (tmp->right) stack.push(tmp->right);
    	    if (tmp->left) stack.push(tmp->left);
	}
        x.printSet();
    }

    void printSet() {
	inorder(root);
        cout << "\n";
    }

    bool contains(int data) { return containsBst(root, data); }

    bool empty() { return !root; }
};

int main() {
    srand(time(NULL));
    Set<int> a, b;

    int n, m;
    cin >> n >> m;
    while (n--) a.insert(rand() % 30 + 1);
    while (m--) b.insert(rand() % 30 + 1);

    cout << "a 집합 : ";
    a.printSet();
    
    cout << "b 집합 : ";
    b.printSet();

    cout << "u 집합 : ";
    a.printUnion(b);

    cout << "x 집합 : ";
    a.printIntersection(b);
}