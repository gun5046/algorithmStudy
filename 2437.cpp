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

int main() {
	int n, w;
	set<int>s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> w;
		s.insert(w);
	}

	set<int>::iterator iter;
	int answer=0;
	int sum = 1;
	for (iter = s.begin(); iter != s.end(); iter++) {
		if (s.begin() == iter) {
			if (*iter != 1) {
				sum = 0;
				break;
			}
		}
		if (*iter > sum + 1) {
			break;
		}
		sum += *iter;
	}
	cout << sum+1;
}