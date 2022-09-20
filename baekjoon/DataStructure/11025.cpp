// f(n,k)=((f(n−1,k)+k−1)mod n)+1, 마지막 남은 수를 구하는 공식
#include <iostream>
using namespace std;

int joseph(int n, int k) {
    if (n == 1)
        return 1;
    return (joseph(n - 1, k) + k-1) % n + 1;
}

int main() {
    int n, k, ans = 0;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        ans = (ans + k - 1) % i + 1;
        cout << ans << ' ';
    }
    cout << ans << '\n';
}
