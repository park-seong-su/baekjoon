#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	int n, s; cin >> n >> s;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	int left = 0, right = 0, sum = arr[0], ans = 100001;
	while (left <= right && right < n) {
		if (sum < s) {
			sum += arr[++right];
		}
		else if (sum == s) {
			ans = min(ans, right - left + 1);
			sum += arr[++right];
		}
		else if (sum > s) {
			ans = min(ans, right - left + 1);
			sum -= arr[left++];
		}
	}
	if (ans == 100001) ans = 0;
	cout << ans << "\n";
	return 0;
}