#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& a, int x) {
	int changeCnt = 0; int underCnt = 0;
	int max = 0; int maxIndex = 0;
	int size = a.size();
	for (int i = 0; i < size; i++) {
		if (max < a[i]) {
			maxIndex = i;
			max = a[i];
		}
	}
	max--;
	for (int i = maxIndex; i >= 0; i--) {
		if (max == a[i]) {
			underCnt++;
			max--;
		}
	}
	changeCnt = a.size() - 1 - underCnt;
	if (changeCnt <= x) return true;
	else return false;
}

int main() {
	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int left = 1;
	int right = n - 1;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(a, mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	cout << ans << "\n";
	return 0;
}