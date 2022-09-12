// 이 코드 왜 틀렸다고 처리 됨?
// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int main() {
//     vector<int> v[5];
//     int k, x, y, big = 1, small = 1;

//     cin >> k;
//     for (int i = 0; i < 6; i++) {
//         cin >> x >> y;
//         v[x].push_back(y);
//     }

//     for (int i = 1; i <= 4; i++) 
//         if (v[i].size() == 1) big *= v[i].at(0);
//         else if (v[i].size() == 2) small *= min(v[i].at(0), v[i].at(1));

//     cout << (big-small) * k << '\n';
// }

#include <iostream>
#include <vector>
using namespace std;

int main() {

	int k; cin >> k;
	vector<pair<int, int>> v(6);
	for (int i = 0; i < 6; i++) {
		cin >> v[i].first >> v[i].second;
	}
	
	int area = -1, ans = -1;
	for (int i = 0; i < 6; i++) {
		int tmp = v[i].second * v[(i + 1) % 6].second;
		if (area == -1 || tmp > area) {
			area = tmp;
			ans = area - v[(i + 3) % 6].second * v[(i + 4) % 6].second;
		}
	}

	cout << ans * k << '\n';
	return 0;
}