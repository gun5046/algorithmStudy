#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
using namespace std;

int n;
vector<int>v;
vector<int>arr;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	priority_queue<pair<int,pair<int,int>>>pq;
	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (i == j) continue;
			int diff = abs(v[j] - v[i]);
			
			pq.push({ -diff , {i,j }});
		}
	}
	
	
}