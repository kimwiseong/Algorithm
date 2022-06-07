/** 골드바흐의 추측 */
#include<bits/stdc++.h>
using namespace std;

bool isPrime[1000005] = {true, true, true, false};

void findPrime() {
    for (int i = 2; i*i < 1000000; i++)
        if (!isPrime[i])
            for (int j = i*i; j < 1000000; j+=i)
                isPrime[j] = true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    findPrime();
    int n;
    while(true) {
        cin >> n;
        if(n == 0) break;

        bool flag = true;
        for (int i = 3; i <= n; i+=2) {
            if(!isPrime[i] && !isPrime[n-i]) {
                cout << n << " = " << i << " + " << n-i << '\n';
                flag = false;
                break;
            }
        }

        if(flag)
            cout << "Goldbach's conjecture is wrong." << '\n';
    }
}