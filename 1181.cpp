#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

bool cmp(string& s1, string& s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	else return s1 < s2;
}

int main() {
	int n; cin >> n;
	set<string> s;
	for (int i = 0; i < n; i++) {
		string temp; cin >> temp;
		s.insert(temp);
	}

	vector<string> save(s.size());
	int index = 0;
	set<string>::iterator iter;
	for (iter = s.begin(); iter != s.end(); iter++) {
		save[index++] = *iter;
	}

	sort(save.begin(), save.end(), cmp);
	for (int i = 0; i < index; i++) {
		cout << save[i] << "\n";
	}
	return 0;
}