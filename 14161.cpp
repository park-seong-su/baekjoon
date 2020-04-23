#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

struct Point {
	ll x, y;
	Point(ll _x, ll _y)
		: x(_x), y(_y) {}
};

vector<pair<Point, Point>> layer;
vector<Point> lazer;

bool cmp(Point p1, Point p2) { //p1기울기 < p2기울기
	return p1.y * p2.x < p2.y * p1.x;
}

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		Point p1(x1, y1); Point p2(x2, y2);
		if (cmp(p1, p2) == false) swap(p1, p2);
		layer.push_back(make_pair(p1, p2));
	}

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		ll x, y; cin >> x >> y;
		lazer.push_back(Point(x, y));
	}
	sort(lazer.begin(), lazer.end(), cmp);
	
	int destroedLayerCount = 0;
	for (int i = 0; i < n; i++) {
		int left = 0;
		int right = m - 1;
		while (left <= right) {
			int mid = (left + right) / 2;
			Point p[3];
			p[0] = layer[i].first;
			p[1] = lazer[mid];
			p[2] = layer[i].second;
			if(cmp(p[0]))
		}
	}

	

	return 0;
}