/** 브루트포스 */
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, ans = 0, card[110];
    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> card[i];
    
    for (int i = 0; i < n-2; i++) 
        for (int j = i+1; j < n-1; j++) 
            for (int k = j+1; k < n; k++) 
                if (card[i] + card[j] + card[k] <= m && card[i] + card[j] + card[k] > ans)
                    ans = card[i] + card[j] + card[k];

    cout << ans << '\n';
}