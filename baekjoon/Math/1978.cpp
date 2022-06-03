/** 소수찾기, 에라토스테네스의 체 */
#include <bits/stdc++.h>
using namespace std;

bool isPrime(int x) {
    if(x < 2) return false;
    for(int i = 2; i*i <= x; i++) 
        if(x%i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int a, n, ans = 0;
    cin >> n;
    while(n--) {
        cin >> a;
        if(isPrime(a)) ans++;
    }
    cout << ans << '\n';
    
}