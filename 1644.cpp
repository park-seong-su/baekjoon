#include <iostream>
#include <vector>
using namespace std;

bool check[4000001];
void go(int x) {
	for (int i = x; i < 2000001; i++) {
		if (check[i] == false) {
			for (int j = i + i; j < 4000001; j += i) {
				check[j] = true;
			}
		}
	}
}

int main() {
	int n; cin >> n;
	check[0] = true; check[1] = true;
	go(2);
	vector<int> arr;
	for (int i = 0; i < 4000001; i++) {
		if (check[i] == false) arr.push_back(i);
	}
	int size = arr.size();
	int left = 0, right = 0, sum = arr[0], ans = 0;
	while (left <= right && right < size) {
		if (sum < n) {
			sum += arr[++right];
		}
		else if (sum == n) {
			ans++;
			sum += arr[++right];
		}
		else if (sum > n) {
			sum -= arr[left++];
		}
	}
	cout << ans << "\n";
	return 0;
}