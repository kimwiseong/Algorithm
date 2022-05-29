/** greedy, 이중벡터 정렬, compare */
#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> x, pair<int, int> y){
    if(x.second == y.second) return x.first < y.first;
    else return x.second < y.second;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int n, start, end; 
    vector<pair<int, int>> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> start >> end;
        s.push_back({start, end});
    }

    sort(s.begin(), s.end(), compare);
    int cnt = 1, max = s[0].second;
    for (int i = 1; i < n; i++) 
        if(max <= s[i].first) {
            cnt++;
            max = s[i].second;
        }
    
    cout << cnt << '\n';
}