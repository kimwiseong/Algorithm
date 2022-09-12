#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, m, num;
    vector<int> A, B, result;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> num;
        A.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        cin >> num;
        B.push_back(num);
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), back_inserter(result));
    cout << result.size() << '\n';
}