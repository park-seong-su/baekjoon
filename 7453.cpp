#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	ll n; cin >> n;
	vector<ll> a(n);
	vector<ll> b(n);
	vector<ll> c(n);
	vector<ll> d(n);
	vector<ll> vec1(n * n);
	vector<ll> vec2(n * n);
	for (ll i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> c[i] >> d[i];
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			vec1[i * n + j] = -(a[i] + b[j]);
			vec2[i * n + j] = c[i] + d[j];
		}
	}
	sort(vec2.begin(), vec2.end());

	ll ans = 0;
	for (ll i = 0; i < n * n; i++) {
		ll lowerBoundIndex = 0;
		ll upperBoundIndex = 0;
		ll x = vec1[i];
		ll left = 0;
		ll right = n * n - 1;
		//lowerBound
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (vec2[mid] == x) {
				lowerBoundIndex = mid;
				right = mid - 1;
			}
			else if (vec2[mid] > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		left = 0;
		right = n * n - 1;
		//upperBound
		while (left <= right) {
			ll mid = (left + right) / 2;
			if (vec2[mid] == x) {
				upperBoundIndex = mid + 1;
				left = mid + 1;
			}
			else if (vec2[mid] > x) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		ans += upperBoundIndex - lowerBoundIndex;
	}

	cout << ans << "\n";
	return 0;
}