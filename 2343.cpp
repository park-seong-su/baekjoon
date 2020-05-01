#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int>& arr, int m, int x) {
	int size = arr.size();
	int sum = 0;
	int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (sum + arr[i] > x) {
			sum = 0;
			cnt++;
		}
		sum += arr[i];
	}
	cnt++;

	if (cnt > m) return false;
	return true;
}

int main() {
	int n, m; cin >> n >> m;
	vector<int> arr(n);
	int sum = 0;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	int left = max;
	int right = sum;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (isPossible(arr, m, mid)) {
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