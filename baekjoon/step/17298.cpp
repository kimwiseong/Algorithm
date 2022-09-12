#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n;
    int a[1000000], nge[1000000];
    stack<int> s;

    cin >> n;
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    for (int i = n-1; i >= 0; i--) {
        while(!s.empty() && s.top() <= a[i]) s.pop();
        
        if(s.empty()) nge[i] = -1;
        else nge[i] = s.top();
        s.push(a[i]);
    }

    for (int i = 0; i < n; i++)
        cout << nge[i] << ' ';
    cout << '\n';
}