#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <deque>
#include <algorithm>
#include <math.h>
#include <utility>
#include <sstream>
#include <cstring>
#include <string>
#include <time.h>

using namespace std;

string s1;
string s2;

bool f = false;
//void gaming(string str) {
//	if (str.length() >= s2.length()) {
//		if (str == s2) f = true;
//		return;
//	}
//
//	str += "A";
//	gaming(str);
//	str.pop_back();
//
//	str+= "B";
//	reverse(str.begin(), str.end());
//	gaming(str);
//	reverse(str.begin(), str.end());
//	str.pop_back();
//	return;
//}


void gaming(string str) {
	if (str.length() <= s1.length()) {
		if (str == s1) f = true;
		return;
	}

	if (str[str.length() - 1] == 'A') {
		gaming(str.substr(0, str.length() - 1));
	}
	if (str[0] == 'B') {
		reverse(str.begin(), str.end());
		gaming(str.substr(0, str.length() - 1));
	}

	return;
}

int main() {
	cin >> s1;
	cin >> s2;

	gaming(s2);

	cout << f;
}