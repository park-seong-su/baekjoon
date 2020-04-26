#include <iostream>
#include <string>
using namespace std;

long long cal(int n) {
	long long ans = 0;
	for (int start = 1, len = 1; start <= n; start *= 10, len++) {
		int end = start * 10 - 1;
		if (end > n) {
			end = n;
		}
		ans += (long long)(end - start + 1) * len;
	}
	return ans;
}

int main() {
	int n;
	long long k;
	cin >> n >> k;
	if (cal(n) < k) {
		cout << "-1\n";
		return 0;
	}
	int left = 1;
	int right = n;
	int ans = 0;
	while (left <= right) {
		int mid = (left + right) / 2;
		long long len = cal(mid);
		if (len < k) { //never answer
			left = mid + 1;
		}
		else { //isPossible answer
			ans = mid; 
			right = mid - 1;
		}
	}
	string s = to_string(ans);
	long long l = cal(ans);
	cout << s[s.length() - (l - k) - 1] << "\n";
	return 0;
}