#include <iostream>
#include <ctime>
#define max(a, b) ( ((a) > (b)) ? (a) : (b) )
using namespace std;

template <typename T>
class Stack {
private:
    struct node {
        T key;
        node *next;
        node(T key, node* next) : key(key), next(next) {}
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
        if (empty()) return 0;
        z = head;
        T v = z->key;
        head = head->next;
        delete z;
        return v;
    };
    
    bool empty() { return !head; };
};

template <typename itemType>
class Set {
private:

    struct avl {
        itemType data;
        int height;
        struct avl *left, *right; 
        avl(itemType data) : data(data), height(1), left(NULL), right(NULL){}
        ~avl() { delete left; delete right; }
    };
	struct avl *root, *tmp;

    avl* insertAvl(avl* node, itemType data) {
		if (empty(node)) return new avl(data);

		if (data < node->data)
            node->left = insertAvl(node->left, data);

		else if (data > node->data) 
            node->right = insertAvl(node->right, data);
		
        node = balance(node);
        return node;
	}

    avl* rotateLL(avl* node) {
        avl* left = node->left;
        node->left = left->right;
        left->right = node;

        setHeight(node); 
        return left;
    }

    avl* rotateRR(avl* node) {
        avl* right = node->right;
        node->right = right->left;
        right->left = node;

        setHeight(node); 
        return right;
    }

    avl* rotateLR(avl* node) {
        node->left = rotateRR(node->left);
        return rotateLL(node);
    }

    avl* rotateRL(avl* node) {
        node->right = rotateLL(node->right);
        return rotateRR(node);
    }

    avl* balance(avl* node) {
        int difference = getDifference(node);
        if (difference >= 2) {
            if (getDifference(node->left) >= 1) node = rotateLL(node);
            else  node = rotateLR(node);
        }

        else if (difference <= -2) {
            if (getDifference(node->right) <= -1) node = rotateRR(node);
            else node = rotateRL(node);
        }

        setHeight(node); 
        return node;
    }

    int getDifference(avl* node) {
        if (node == NULL) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }   

    int getHeight(avl* node) {
        if (node == NULL) return 0;
        return node->height;    
    }

    void setHeight(avl* node) {
        node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    }

    void inorder(avl* node) {
		if (empty(node)) return;
		inorder(node->left);
		cout << node->data << " ";
		inorder(node->right);
	}

    bool containsAvl(avl* node, int data) {
		if (empty(node))  return false;
		return node->data == data || containsAvl(node->left, data) || containsAvl(node->right, data);
	}

    bool empty(avl* node) { return !node; }

public:
	Set() { root = NULL; }
    ~Set() { delete root; }
    
    void printUnion(Set& s) {
		Set<int> u;
		if (root == NULL) return s.print();
		if (s.root == NULL) return print();

		Stack<avl*> stack;
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

		u.print();
	}

    void printIntersection(Set& s) {
		Set<int> x;
		Stack<avl*> stack;
		stack.push(root); 

		while (!stack.empty()) {
            tmp = stack.pop();

			if (s.contains(tmp->data)) x.insert(tmp->data);
			if (tmp->right) stack.push(tmp->right);
			if (tmp->left) stack.push(tmp->left);
		}
        x.print();
	}

    void insert(itemType data) {
		if (!containsAvl(root, data)) 
            root = insertAvl(root, data);
	}

	void print() {
		inorder(root);
        cout << "\n";
	}

    bool contains(itemType data) { return containsAvl(root, data); }

    bool empty() { return !root; }
};

int main() {
    srand(time(NULL));
    Set<int> a, b;

    int n, m;
    cin >> m >> n;
    for (int i = 0; i < n; i++) a.insert(rand() % n + 1);
    for (int i = 0; i < m; i++) b.insert(rand() % m + 1);

    cout << "A set : ";
    a.print();
    
    cout << "B set : ";
    b.print();

    cout << "U set : ";
    a.printUnion(b);
    
    cout << "X set : ";
    a.printIntersection(b);
}