#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<string, string>& s1, pair<string, string>& s2) {
	return s1.second > s2.second;
}

int main() {
	int n; cin >> n;
	vector<pair<string, string>> a(n);
	for (int i = 0; i < n; i++) {
		string s[4];
		cin >> s[0] >> s[1] >> s[2] >> s[3];
		a[i].first = s[0];
		a[i].second += s[3];
		if (s[2].size() == 1) s[2] = '0' + s[2];
		a[i].second += s[2];
		if (s[1].size() == 1) s[1] = '0' + s[1];
		a[i].second += s[1];
	}

	sort(a.begin(), a.end(), cmp);
	cout << a[0].first << "\n";
	cout << a[n - 1].first << "\n";

	return 0;
}