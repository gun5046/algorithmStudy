#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#define INF 99999999
using namespace std;
int n, m;
vector<pair<int, int>>v[101];
int arr[101];
vector<int>ans;
bool check = false;

int main() {
	cin >> n >> m;
	
	for (int i = 0; i < 101; i++) {
		arr[i] = -INF;
	}

	for (int i = 0; i < m; i++) {
		int n1, n2, n3;
		cin >> n1 >>  n2 >>n3;
		v[n1].push_back({ n2, n3 });
		
	}

	int start = 1;
	arr[1] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 0; k < v[j].size(); k++) {
				int next = v[j][k].first;
				int val = v[j][k].second;

				if (arr[next] >= arr[j] + val) {
					continue;
				}
				arr[next] = arr[j] + val;
			}
		}
	}
	
	
	if (check) {
		cout << -1;
		return 0;
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << " ";
	}
	
}