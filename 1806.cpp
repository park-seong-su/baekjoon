#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, s; cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int left = 0, right = 0, sum = arr[0], ans = 123456789;
	while (left <= right && right < n) {
		if (sum < s) {
			right++;
			if (right == n) break;
			sum += arr[right];
		}
		else if (sum >= s) {
			ans = min(ans, right - left + 1);
			sum -= arr[left++];
		}
	}
	if (ans == 123456789) ans = 0;
	cout << ans << "\n";
	return 0;
}