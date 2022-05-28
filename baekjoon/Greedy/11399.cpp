/** greedy */
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, p[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    sort(p, p+n);

    int ans = p[0];
    for (int i = 1; i < n; i++)
        for (int j = 0; j <= i; j++)
            ans += p[j];
    
    cout << ans << '\n';
}