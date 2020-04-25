#include <iostream>
#include <algorithm>
using namespace std;

int parent[201];
int r[201];
int citys[1001];

int Find(int x) {
	if (x == parent[x]) {
		return x;
	}
	else {
		return parent[x] = Find(parent[x]);
	}
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) return;
	if (r[x] < r[y]) swap(x, y);
	parent[y] = x;
	if (r[x] == r[y]) r[x] = r[y] + 1;
}

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) parent[i] = i;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int k; cin >> k;
			if (k == 0) continue;
			int x = Find(i);
			int y = Find(j);
			if (x != y) Union(i, j);
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> citys[i];
	}

	bool ans = true; //true->yes, false->no
	for (int i = 0; i < m - 1; i++) {
		int x = Find(citys[i]);
		int y = Find(citys[i + 1]);
		if (x != y) {
			ans = false;
			break;
		}
	}

	if (ans == true) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}