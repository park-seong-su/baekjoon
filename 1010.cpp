#include <iostream>
using namespace std;

long long go(int m, int n) {
	long long result = 1;
	for (int i = n + 1; i <= m; i++) {
		result *= (long long)i;
	}
	return result;
}

int main() {
	int t; cin >> t;
	while (t--) {
		int n, m; cin >> n >> m;
		n = (m - n > n) ? m - n : n;
		long long up = go(m, n);
		long long down = go(m - n, 0);
		cout << up / down << "\n";
	}
	return 0;
}