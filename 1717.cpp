#include <iostream>
#include <algorithm>
using namespace std;

int parent[1000001];
int r[1000001];

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
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i <= n; i++) parent[i] = i;

	for (int i = 0; i < m; i++) {
		int j, a, b; cin >> j >> a >> b;
		if (j == 0) {
			Union(a, b);
		}
		else if(j == 1) {
			int x = Find(a);
			int y = Find(b);
			if (x == y) cout << "YES\n";
			else cout << "NO\n";
		}
	}
	return 0;
}