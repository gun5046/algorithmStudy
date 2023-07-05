#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
#include <sstream>
#include <list>
#include <deque>
#include <time.h>
using namespace std;


int n, m;
vector<int>v;
int res[2001][2001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> n;
	
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	
	for (int i = 1; i <= n; i++) {
		res[i][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (v[i] == v[i + 1]) {
			res[i][i + 1]=1;
		}
	}

	for (int i = 2; i <= n - 1; i++) {
		for (int j = 1; i + j <= n; j++) {
			if (v[j] == v[i + j] && res[j + 1][i + j - 1] == 1) {
				res[j][i + j] = 1;
			}
		}
	}

	cin >> m;
	
	

	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;

		cout << res[start][end]<<"\n";
	}

}