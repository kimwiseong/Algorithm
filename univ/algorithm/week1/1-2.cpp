#include <iostream>
#include <cmath>
using namespace std;

const int N = 10000;

int main() {
    int i, j, a[N+1];
    int count = 0;   
    int prime = 0;

    for (a[1] = 0, i = 2; i <= N; i++)  
        a[i] = 1;

    //기존코드
    // for (i = 2; i <= N/2; i++) { 
    //     for (j = 2; j <= N/i; j++) {
    //             a[i*j] = 0;
    //             count++;
    //     }   
    // }

    //개선 코드
    for (i = 2; i*i <= N; i++) {
		count++;
		if (a[i]) {
            for (j = i*i; j <= N; j+=i) {
                count++;
                a[j] = 0;
            }
		}
	}

    for (i = 1; i <= N; i++) {
        if (a[i]) {
            cout << i << ' ';
            prime = i;
        }
    }

    cout << '\n';
    cout << "실행된 곱셈연산 회수 : " << count << '\n';
    cout << "N보다 작은 최대 소수 : " << prime << '\n';
}