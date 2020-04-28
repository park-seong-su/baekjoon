#include <iostream>
using namespace std;
typedef long long ll;

bool isPossible(double x, double y, ll curz, ll playCnt) {
	x += playCnt;
	y += playCnt;
	ll changez = (y * 100) / x;
	if (curz < changez) return true;
	else return false;
}

int main() {
	double x, y; cin >> x >> y;
	ll curz = (y * 100) / x;
	
	ll left = 1;
	ll right = 2000000000;
	ll ans = -1;
	while (left <= right) {
		ll mid = (left + right) / 2;
		if (isPossible(x, y, curz, mid)) {
			ans = mid;
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	
	cout << ans << "\n";
	return 0;
}