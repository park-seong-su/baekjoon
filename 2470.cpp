#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	vector<int> ans(2);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0, right = n - 1;
	int minSum = 2000000001;
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (minSum > abs(sum)) {
			minSum = abs(sum);
			ans[0] = arr[left];
			ans[1] = arr[right];
		}
		if (sum < 0) left++;
		else right--;
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1] << "\n";
	return 0;
}