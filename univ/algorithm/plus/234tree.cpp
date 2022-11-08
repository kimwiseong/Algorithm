/**
 * 2-3-4-tree
 */
#include <iostream>
#include <vector>
#include <queue>
#include <limits>
using namespace std;

template<typename T>
class Tree234 {
	struct node {
		vector<T> value;
		vector<node*> child;

		node(const T& x): value(1, x), child(2) {}
		node(const T& x, node* l, node* r): value(1, x), child(2) {
			child[0] = l;
			child[1] = r;
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

    node* root;
	size_t m_count;
	unsigned m_levels;

public:
	Tree234(): root(NULL), m_count(0), m_levels(0) {}

	size_t size() const { return m_count; }
	unsigned levels() const { return m_levels; }

	bool insert(const T& x) {
		if(!root) {
			root = new node(x);
			++m_levels;
			return true;
		}

		if( root->split4() ) ++m_levels;
		if(!insert(root, x)) return false;
		
        ++m_count;
		return true;
	}

    void inorder() {        
        inorder(root);
    }

	bool isValid() const {
		T prev = numeric_limits<T>::min();
		return isValid(root, prev);	
	}

private:
	bool insert(node* cur, const T& x) {
		size_t i, n = cur->value.size();
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

	bool isValid(const node* p, T& prev) const {
		if(!p) return true;

		int i, n;
		for(i = 0, n = p->value.size(); i < n; ++i) {
			if(!isValid(p->child[i], prev)) return false;
			if(prev >= p->value[i]) return false;
			prev = p->value[i];
		}
		return isValid(p->child[i], prev);
	}

    void inorder(node *node) {
        if (!node) return;

        inorder(node->child[0]);
        for (int i = 0; i < node->value.size(); i++) {
            // cout << node->value[i] << ' ';
            inorder(node->child[i+1]);
        }
    }

};

int main() {
	srand(time(NULL));
    int N = 1000;

	//2-3-4-tree
	Tree234<int> t;
	for(int i = 0; i < N; i++) {
		t.insert( rand() % 1000 );
	}
    t.inorder();

	cout << "\n2-3-4-Tree\n" 
			"Size: " << t.size() << "\n" 
			"Levels: " << t.levels() << "\n"
            "Valid: " << (t.isValid() ? "yes" : "NO" ) << std::endl;
}
