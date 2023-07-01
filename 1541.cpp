#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int main() {

	string s;
	cin >> s;
	string temp="";
	vector< string>num;
	vector<char>op;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '+' || s[i] == '-') {
			op.push_back(s[i]);
			num.push_back(temp);
			temp = "";
		}
		else {
			temp += s[i];
		}
	}
	num.push_back(temp);
	bool flag = false;
	int sum = 0;
	for (int i = 0; i < op.size(); i++) {
		int n = stoi(num[i]);
		if (!flag) {
			sum += n;
		}
		else {
			sum -= n;
		}
		if (op[i] == '-') {
			flag = true;
		}
	}

	if (flag) {
		sum -= stoi(num[num.size() - 1]);
	}
	else {
		sum += stoi(num[num.size() - 1]);
	}
	cout << sum;
}