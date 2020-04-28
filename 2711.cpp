#include <iostream>
#include <string>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int k; string s;
		cin >> k >> s;
		k--;
		int size = s.size();
		for (int i = 0; i < size; i++) {
			if (i == k) continue;
			cout << s[i];
		}
		cout << "\n";
	}
	return 0;
}