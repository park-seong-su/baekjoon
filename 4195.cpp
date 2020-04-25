#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

map<string, string> parent;
map<string, int> r;
map<string, int> cnt;

string Find(string s) {
	if (s == parent[s]) {
		return s;
	}
	else {
		return parent[s] = Find(parent[s]);
	}
}

void Union(string x, string y) {
	if (x == y) return;
	if (r[x] < r[y]) swap(r[x], r[y]); //always rank[x] >= rank[y]
	parent[y] = x;
	cnt[x] += cnt[y];
	if (r[x] == r[y]) r[x] = r[y] + 1;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int test; cin >> test;
	while (test--) {
		int f; cin >> f;
		parent.clear(); r.clear(); cnt.clear();
		for (int i = 0; i < f; i++) {
			string user1, user2;
			cin >> user1 >> user2;
			if (parent[user1] == "") { //initialize
				r[user1] = 0;
				cnt[user1] = 1;
				parent[user1] = user1;
			}
			if (parent[user2] == "") { //initialize
				r[user2] = 0;
				cnt[user2] = 1;
				parent[user2] = user2;
			}
			user1 = Find(user1);
			user2 = Find(user2);
			Union(user1, user2);
			cout << cnt[user1] << "\n";
		}
	}
	return 0;
}