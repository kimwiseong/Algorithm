#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

template <typename itemType>
class PQ {
    private:
    itemType *a;
    int N;
    int count;

    public:
    PQ(int m) {
        N = m;
        a = new itemType[N];
        count = 0;
    }
    ~PQ() { delete a; }

    int getCount() { return count; } 

    void swap(int i, int j) {
        itemType t = a[i]; a[i] = a[j]; a[j] = t; 
    }

    void initRandCase() {
        for (int i = 0; i < N; i++)
            a[i] = rand() % N;
    }

    void initWorstCase() {
        for (int i = 0; i < N; i++)
            a[i] = i;
    }

    void MakeHeap(int root, int lastNode) {      
        int parent, left, right, son, rootValue;
    
        parent = root;
        rootValue = a[root];
        left = 2 * parent + 1;
        right = left + 1;

        while (left <= lastNode)  {
            count++;
            if (right <= lastNode && a[left] < a[right])
                son = right;
            else  son = left;
            count++;
            if (rootValue < a[son])  {
                a[parent] = a[son];
                parent = son;
                left = parent * 2 + 1;
                right = left + 1;   
            }
            else break; 
        }

        a[parent] = rootValue; 
    }

    void heapsort() {
        int i;
        for (i = N/2; i > 0; i--) 
            MakeHeap(i-1, N-1);

        for (i = N-1; i > 0; i--) {
            swap(0, i);
            MakeHeap(0, i-1);
        }
    }

    void print() {
        for (int i = 0; i < N; i++)
            cout << a[i] << ' ';
        cout << '\n';
    }
};

int main() {
    srand(time(NULL));
    int m;
    cin >> m;

    PQ<int> pq(m);
    pq.initRandCase();
    pq.heapsort();
    // pq.print();
    cout << "random case 비교 연산횟수 : " << pq.getCount() << '\n';

    PQ<int> wc(m);
    wc.initWorstCase();
    wc.heapsort();
    // wc.print();
    cout << "worst case 비교 연산횟수 : " << wc.getCount() << '\n';
}