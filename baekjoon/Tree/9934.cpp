#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

vector<int> tree[11];
int vertex[1024];

void insert(int depth, int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    tree[depth].push_back(vertex[mid]);
    insert(depth + 1, start, mid);
    insert(depth + 1, mid + 1, end);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> k;

    int size = pow(2, k) - 1;
    for (int i = 0; i < size; i++)
        cin >> vertex[i];

    insert(0, 0, size);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < tree[i].size(); j++)
            cout << tree[i][j] << " ";
        cout << "\n";
    }
}