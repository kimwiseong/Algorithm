/** deque, stack, 에디터 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    string s; cin >> s;
    deque<char> dq;
    stack<char> tmp;

    for (int i = 0; i < s.length(); i++)
        dq.push_back(s[i]);
    
    int m; cin >> m;
    while(m--) {
        char cmd; cin >> cmd;
        if(cmd == 'L') {
            if(dq.empty()) continue;
            tmp.push(dq.back());
            dq.pop_back();
        }

        else if(cmd == 'D') {
            if (tmp.empty()) continue;
            dq.push_back(tmp.top());
            tmp.pop();
        }

        else if(cmd == 'B') {
            if(dq.empty()) continue;
            dq.pop_back();
        }

        else if(cmd == 'P'){
            char c; cin >> c;
            dq.push_back(c);
        }
    }

    while(!tmp.empty()) {
        dq.push_back(tmp.top());
        tmp.pop();
    }

    while(!dq.empty()) {
        cout << dq.front();
        dq.pop_front();
    }
    cout << '\n';
}