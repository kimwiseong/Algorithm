/**stack 단어 뒤집기 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    cin.ignore();
    while(t--) {
        string s;
        getline(cin, s);
        s += ' ';
        stack<char> stack;
        for (char ch : s) {
            if(ch == ' ') {
                while(!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                cout << ' ';
            }
            else stack.push(ch);
        }
        cout<<'\n';
    }
}
