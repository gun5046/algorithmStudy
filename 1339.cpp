#include <iostream>
#include <vector>
#include <cstring>
#include <math.h>
#include <utility>
#include <map>
#include <queue>
#define maximum 8
using namespace std;

int n;
vector<string>str;
map<int, int> m;
int wordmath();
int main() {
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string t="";
		for (int j = 0; j < 8 - s.size(); j++) {
			t += '*';
		}
		s = t + s;
		str.push_back(s);
	}
	m.insert({ 'A', 0 });
	m.insert({ 'B', 0 });
	m.insert({ 'C', 0 });
	m.insert({ 'D', 0 });
	m.insert({ 'E', 0 });
	m.insert({ 'F', 0 });
	m.insert({ 'G', 0 });
	m.insert({ 'H', 0 });
	m.insert({ 'i', 0 });
	m.insert({ 'J', 0 });
	cout << wordmath();
}

int wordmath() {
	int cnt = 9;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < maximum; j++) {
			if (str[i][j] == '*') continue;
			m[str[i][j]] = m[str[i][j]] + pow(10, 7 - j);
		}
	}
	map<int, int> ::iterator iter;
	priority_queue<pair<int,char>>pq;
	for (iter = m.begin(); iter != m.end(); iter++) {
		pq.push({ iter->second, iter->first });
	}
	while (!pq.empty()) {
		int m =pq.top().first;
		pq.pop();
		sum += m* cnt;
	}
	return sum;
}
