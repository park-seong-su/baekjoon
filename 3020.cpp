#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, h; cin >> n >> h;
	n /= 2;
	vector<int> odd(n + 1);
	vector<int> even(n + 1);
	vector<int> upSum(h + 1);
	vector<int> downSum(h + 1);
	for (int i = 1; i <= n; i++) {
		cin >> odd[i] >> even[i];
	}
	sort(odd.begin(), odd.end());
	sort(even.begin(), even.end());

	for (int k = 1; k <= h; k++) {
		int left = 1;
		int right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (odd[mid] < k) {
				left = mid + 1;
			}
			else {
				upSum[k] = n - mid + 1;
				right = mid - 1;
			}
		}
	}
	int j = h;
	for (int k = 1; k <= h; k++) {
		int left = 1;
		int right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (even[mid] < k) {
				left = mid + 1;
			}
			else {
				downSum[j] = n - mid + 1;
				right = mid - 1;
			}
		}
		j--;
	}
	
	int min = 100000000;
	int cnt = 0;
	for (int i = 1; i <= h; i++) {
		if (min > (upSum[i] + downSum[i])) {
			min = upSum[i] + downSum[i];
		}
	}
	for (int i = 1; i <= h; i++) {
		if ((upSum[i] + downSum[i]) == min) {
			cnt++;
		}
	}
	cout << min << " " << cnt << "\n";
	return 0;
}