#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string s;
string t;
int main() {
	cin >> s;
	cin >> t;

	int s_size = s.size();
	int t_size = t.size();
	for (int i = t.size() - 1; i + 1 > s_size; i = t.size() - 1) {
		if (t[i] == 'B') {
			t = t.substr(0, i);
			reverse(t.begin(), t.end());
		}
		else {
			t = t.substr(0, i);
		}
	}
	if (s == t) {
		cout << "1";
	}
	else {
		cout << "0";
	}
}