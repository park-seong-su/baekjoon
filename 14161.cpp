#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y;
	Point() {}
	Point(ll _x, ll _y) : x(_x), y(_y) {}
};

bool cmp(Point p1, Point p2) { //p1기울기 < p2기울기
	return p1.x * p2.y < p2.x * p1.y;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	vector<pair<Point, Point>> layer;
	vector<Point> lazer;
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1); Point p2(x2, y2);
		if (cmp(p1, p2) == false) swap(p1, p2);
		layer.push_back(make_pair(p1, p2));
	}
	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		ll x, y;
		cin >> x >> y;
		lazer.push_back(Point(x, y));
	}
	sort(lazer.begin(), lazer.end(), cmp);

	int destroyedLayerCount = 0;
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = m - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			Point p[3];
			p[0] = layer[i].first;
			p[1] = lazer[mid];
			p[2] = layer[i].second;
			if (cmp(p[2], p[1]) == true) { //p[2]기울기 < p[1]기울기
				right = mid - 1;
			}
			else if (cmp(p[1], p[0]) == true) { //p[1]기울기 < p[0]기울기
				left = mid + 1;
			}
			else {
				destroyedLayerCount++;
				break;
			}
		}
	}

	int ans = n - destroyedLayerCount;
	cout << ans << "\n";
	return 0;
}