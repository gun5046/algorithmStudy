#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <stack>

using namespace std;

vector<int>findPattern(string p) {
	int size = p.size();
	vector<int>pi(size);
	
	for (int i = 1, j = 0; i < size; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}
int c;
vector<int>kmp(string s, string p) {
	vector<int>ans;
	int cnt = 0;
	vector<int>pi = findPattern(p);
	int ssize = s.size();
	int psize = p.size();
	for (int i = 0, j = 0; i < ssize; i++) {
		while (j>0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == psize - 1) {
				ans.push_back(i-psize+1);
				cnt++;
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
	c = cnt;
	return ans;
}
int main() {
	string s, p;
	cin >> s >> p;
	vector<int> ans = kmp(s, p);
	for (int i : ans) {
		cout << i << "\n";
	}
	cout << c;
}