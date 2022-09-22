#include<iostream>
using namespace std;

int t[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int n, k, m = -1000;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        t[i] += t[i-1];
    }
    
    for (int i = k; i <= n; i++)
        m = max(m, t[i]- t[i-k]);
    cout << m << '\n';
}