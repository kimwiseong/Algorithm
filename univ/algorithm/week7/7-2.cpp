#include <iostream>
#include <cstdlib>
#include <ctime>
#define itemType int
using namespace std;

class HT {
private:
    struct node { //chaining
        itemType key;
        struct node *next;
        node(itemType key, node* next) : key(key), next(next) {}
        ~node() { delete next; }
    };
    struct node **hashTable;
    int m, cnt;

public:
    HT(int m) {
        hashTable = new node*[m];
        cnt = 0;
        this->m = m;
    }

    ~HT() { delete hashTable; }

    void add(int k) {
        int hk = getHashKey(k);
        hashTable[hk] = new node(k, hashTable[hk]);
    }

    bool search(int k) {
        int hk = getHashKey(k); cnt++;
        return hashTable[hk]->key == k;
    }


    void print() {
        for (int i = 0; i < m; i++){
            if (isempty(i)) continue;

            for (struct node *tmp = hashTable[i]; tmp; tmp = tmp->next) 
                cout << tmp->key << " - ";
            cout << '\n';
        }
    }

    int getCount() { return cnt; }

private:
    int getHashKey(int k) { return k % m; }
    bool isempty(int hk) { return hashTable[hk] == NULL; }
}; 

int main() {
    srand(time(NULL));
    int n, m; //100, 1009; 
    cin >> n >> m;

    HT hash(m);
    int *data = new int[n];

    for (int i = 0; i < n; i++) {
        data[i] = rand() % n;
        hash.add(data[i]);
    }
    hash.print();

    for (int i = 0; i < n; i++) 
        hash.search(data[i]);
    
    cout << "평균비교횟수 : " << hash.getCount()/n << '\n';
}