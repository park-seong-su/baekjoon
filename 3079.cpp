#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossible(vector<long long>& a, long long x, long long m) {
	int size = a.size();
	long long cnt = 0;
	for (int i = 0; i < size; i++) {
		cnt += x / a[i];
	}
	if (cnt >= m) return true;
	else return false;
}

int main() {
	int n, m; cin >> n >> m;
	vector<long long> a(n);
	long long min = 1000000001;
	long long max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (min > a[i]) min = a[i];
		if (max < a[i]) max = a[i];
	}
	sort(a.begin(), a.end());

	long long left = min;
	long long right = m * max;
	long long ans = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		if (isPossible(a, mid, m)) {
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