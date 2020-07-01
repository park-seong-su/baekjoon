#include <iostream>
using namespace std;

int arr[10001];
int ans;

/*
//O(N^3)
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += arr[k];
			}
			if (sum == m) ans += 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
*/

/*
//O(N^2)
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = i; j < n; j++) {
			sum += arr[j];
			if (sum == m) ans += 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
*/

//O(N) -> two pointer
int main() {
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> arr[i];
	int left = 0, right = 0, sum = arr[0];
	while (left <= right && right < n) {
		if (sum < m) {
			sum += arr[++right];
		}
		else if (sum == m) {
			ans++;
			sum += arr[++right];
		}
		else if (sum > m) {
			sum -= arr[left++];
			if (left > right && left < n) {
				right = left;
				sum = arr[left];
			}
		}
	}
	cout << ans << "\n";
	return 0;
}