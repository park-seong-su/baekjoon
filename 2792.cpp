#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int n, int x) {
	int size = arr.size();
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] % x == 0) {
			cnt += arr[i] / x;
		}
		else {
			cnt += arr[i] / x;
			cnt++;
		}
	}
	if (cnt > n) return false;
	else return true;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> arr(m);
	int max = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		if (max < arr[i]) max = arr[i];
	}
	int left = 1;
	int right = max;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(arr, n, mid)) {
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