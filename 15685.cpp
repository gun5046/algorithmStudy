#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <queue>
#include <stack>
#include <string>
#include <math.h>
#include <sstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int n;

bool arr[101][101];
vector<pair<pair<int,int>,pair<int,int>>>dragon;

int dy[4] = { 0,-1,0,1 };
int dx[4] = {1,0,-1,0};
int cnt = 0;
void dragonCurve(int x, int y, int g, vector<int> v) {
	if (pow(2,g) == v.size()) {
		return;
	}
	vector<int>v1;
	int size = v.size();
	int nx=x;
	int ny=y;
	
	for (int i = size - 1; i >= 0; i--) {
		int nd = v[i]+1;
		if (nd > 3) nd = 0;
		v.push_back(nd);
		
		nx = nx + dx[nd];
		ny = ny + dy[nd];
		if(nx>=0 && ny>=0 && nx<=100 && ny <=100)
			arr[ny][nx] = 1;
	}
	dragonCurve(nx, ny, g, v);
	// 0 1 2 3   동북서남 / 시계방향 -> 동남서북   0 0 , 1 3 , 2 2 , 3 1 , stack
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		dragon.push_back({ {x, y},{d, g} });
	}

	for (int i = 0; i < dragon.size(); i++) {
		int x = dragon[i].first.first;
		int y = dragon[i].first.second;
		int d = dragon[i].second.first;
		int g = dragon[i].second.second;
		
		
		arr[y][x] = 1;
		vector<int>v;
		v.push_back(d);
		arr[y+dy[d]][x+dx[d]] = 1;
		dragonCurve(x+dx[d], y+dy[d], g, v);
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (arr[i][j] == 0 || arr[i + 1][j] == 0 || arr[i][j + 1] == 0 || arr[i + 1][j + 1] == 0) continue;
			cnt++;
		}
	}
	cout << cnt;
}