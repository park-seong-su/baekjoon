#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[100001];
vector<int> ans;

int main() {
	int g; cin >> g;
	for (int i = 0; i < 100001; i++) arr[i] = i * i;
	int left = 1, right = 1;
	while (left <= right && right < 100001) {
		int temp = arr[right] - arr[left];
		if (temp < g) {
			right++;
		}
		else if (temp == g) {
			ans.push_back(right);
			right++;
		}
		else if (temp > g) {
			left++;
		}
	}
	if (ans.empty() == true) {
		cout << "-1\n";
		return 0;
	}
	sort(ans.begin(), ans.end());
	int size = ans.size();
	for (int i = 0; i < size; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}