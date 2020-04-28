#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;

vector<pair<int, int>> a[100001];
bool check[100001];

bool isPossible(int limit, int go, int from) {
	memset(check, false, sizeof(check));
	queue<int> q;

	q.push(go);
	check[go] = true;
	while (!q.empty()) {
		int x = q.front();
		if (x == from) return true;
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].first;
			int w = a[x][i].second;
			if (check[y] == false && limit <= w) {
				q.push(y);
				check[y] = true;
			}
		}
	}
	return false;
}

int main() {
	int n, m; cin >> n >> m;
	int max = 0;
	int min = 1000000001;
	for (int i = 0; i < m; i++) {
		int x, y, z; cin >> x >> y >> z;
		a[x].push_back(make_pair(y, z));
		a[y].push_back(make_pair(x, z));
		if (z > max) max = z;
		if (min > z) min = z;
	}
	int go, from; cin >> go >> from;
	
	int left = min;
	int right = max;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(mid, go, from)) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans << "\n";
	return 0;
}