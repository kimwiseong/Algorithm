/** 유클리드 호제법 */
#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y) {
    if(y == 0) return x;
    return gcd(y, x%y);
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, b, t;
    cin >> t;
    while(t--) {
        cin >> a >> b;
        cout << a*b/gcd(a,b) << '\n';
    }
}