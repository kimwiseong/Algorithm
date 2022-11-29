#include <iostream>
#include <cmath>
using namespace std;

int fib(int n) {
    if (n == 1) return 1;
    if (n == 2) return 1;
    else return fib(n-1) + fib(n-2);
}

int dp[10001][2101] = { 0,};
int main() {
    int N = 10000;
    int M = 2090; //10000번째 피보나치 수 길이
    int i, j, tmp = 0, flag = 0;
    
    dp[0][0] = 0;
    dp[1][0] = 1;
    dp[2][0] = 1;
    
    for (i = 3; i <= N; i++) {
        for (j = 0; j < M; j++) {
            tmp = dp[i-1][j] + dp[i-2][j] + flag;
            dp[i][j] = tmp % 10;

            if (tmp < 10) flag = 0;
            else  flag = 1;
        }
    }
    cout << N << "번째 피보나치 수 : " << '\n';
    for (i = M-1; i >= 0; i--) {
        cout << dp[N][i];
    }
    
    cout << "\n20번째 피보나치 수 : " << fib(20) << '\n';
}
