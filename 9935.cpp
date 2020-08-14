#include <iostream>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
	string s, t, p; cin >> s >> t;
	int sLen = s.length(), pLen = t.length();
	for (int i = pLen - 1; i >= 0; i--) p += t[i];
	stack<char> stack1;
	for (int i = 0; i < sLen; i++) {
		stack1.push(s[i]);
		if (stack1.size() >= pLen && stack1.top() == p[0]) {
			string temp;
			for (int j = 0; j < pLen; j++) {
				temp += stack1.top();
				stack1.pop();
			}
			if (temp != p) {
				int tempLen = temp.length();
				for (int j = tempLen - 1; j >= 0; j--) {
					stack1.push(temp[j]);
				}
			}
		}
	}
	int stackSize = stack1.size();
	string ans;
	if (stackSize == 0) ans = "FRULA";
	else {
		string ansReverse;
		for (int i = 0; i < stackSize; i++) {
			ansReverse += stack1.top();
			stack1.pop();
		}
		for (int i = stackSize - 1; i >= 0; i--) {
			ans += ansReverse[i];
		}
	}
	cout << ans << "\n";
	return 0;
}