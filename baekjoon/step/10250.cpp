#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t, h, w, n;
    cin >> t;

    while(t--) {
        cin >> h >> w >> n;
        int floor = (n % h) * 100;
        int num = int(n/h) + 1;
        
        if (floor == 0) cout << h*100 + num -1 << '\n';
        else cout << floor + num << '\n';
    }
} 
