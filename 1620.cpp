#include <iostream>
#include <algorithm>
using namespace std;

string s[100001];
pair<string, int> temp[100001];

bool cmp(pair<string, int>& temp1, pair<string, int>& temp2) {
	return temp1.first < temp2.first;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		temp[i].first = s[i];
		temp[i].second = i;
	}
	sort(temp, temp + n, cmp);
	for (int i = 0; i < m; i++) {
		string q; cin >> q;
		if (65 <= ((int)q[0]) && ((int)q[0]) <= 90) { //A~Z
			int left = 0;
			int right = n - 1;
			while (left <= right) {
				int mid = (left + right) / 2;
				if (temp[mid].first < q) {
					left = mid + 1;
				}
				else if (q < temp[mid].first) {
					right = mid - 1;
				}
				else {
					cout << temp[mid].second + 1 << "\n";
					break;
				}
			}
		}
		else {
			int x = atoi(q.c_str()) - 1; //stringToInt
			cout << s[x] << "\n";
		}
	}
	return 0;
}
