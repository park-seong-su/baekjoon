#include <iostream>
#include <algorithm>
using namespace std;

int parent[100001];
int gi[100001];

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
	parent[y] = x;
}

int main() {
	int g, p; cin >> g >> p;
	int ans = 0;
	for (int i = 0; i <= g; i++) parent[i] = i;
	for (int i = 0; i < p; i++) {
		cin >> gi[i];
	}

	for (int i = 0; i < p; i++) {
		int k = Find(gi[i]);
		if (k == 0) break;
		Union(k - 1, k);
		ans++;
	}
	cout << ans << "\n";
	return 0;
}