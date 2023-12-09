#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <utility>
#include <map>
using namespace std;

int n;
int d;
int k;
int c;
vector<int>v;
map<int, int>m;
int result = 0;
int main() {
	cin >> n >> d >> k >> c;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		v.push_back(num);
	}
	m.insert({ c ,1});
	for (int i = 0; i < k; i++) {
		if (m.find(v[i]) == m.end()) {
			m.insert({ v[i], 1 });
		}
		else {
			m[v[i]]++;
		}
	}
	result = m.size();
	int sz = v.size();
	for (int i = 0; i < sz; i++) {
		v.push_back(v[i]);
	}
	for (int left = 0; left < v.size() - k; left++) {
		if (m[v[left]] == 1) {
			m.erase(v[left]);
		}
		else {
			m[v[left]]--;
		}

		if (m.find(v[left + k]) == m.end()) {
			m.insert({ v[left + k], 1 });
		}
		else {
			m[v[left + k]]++;
		}
		result = max(result, (int)m.size());
	}

	cout << result;
}