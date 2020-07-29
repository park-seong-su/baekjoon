#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int left = 0, right = n - 1, min = 2000000001;
	vector<int> ans(2);
	while (left < right) {
		int sum = arr[left] + arr[right];
		if (min > abs(sum)) {
			min = abs(sum);
			ans[0] = arr[left];
			ans[1] = arr[right];
		}
		if (sum > 0) {
			right--;
		}
		else { //sum < 0
			left++;
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << ans[1] << "\n";
	return 0;
}