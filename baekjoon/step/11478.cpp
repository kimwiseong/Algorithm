#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    string s;
    cin >> s;

    unordered_set<string> result;
    int n = s.size();
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            result.insert(s.substr(i, j));

    cout << result.size() << '\n';
}