#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, k; cin >> n >> k;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int sum = 0, ans = 0;
	for (int i = 0; i < k; i++) {
		sum += arr[i];
		ans += arr[i];
	}
	for (int i = 1; i <= n - k; i++) {
		int left = i - 1;
		int right = i + k - 1;
		sum = sum - arr[left] + arr[right];
		ans = max(sum, ans);
	}
	cout << ans << "\n";
	return 0;
}