#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
#define INF 99999
using namespace std; 


int w, h;
int res=INF;
char box[21][21];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
vector<pair<int,int>>v;
vector <int> dis[11];
string str;

bool visited[21][21];
int dist=0;
priority_queue<int>pq;

void permutation(int here, int sum) {
	if (here == v.size() - 1) {
		pq.push(-sum);
		return;
	}
	for (int i = 0; i < dis[here].size(); i++) {
		int next = sum + dis[here][i];
		cout << here << dis[here][i]<<"\n";
		permutation(here+1, next);
	}
	
}


void robotCleaner(int start_x, int start_y, int c) {
	memset(visited, 0, sizeof(visited));

	queue<pair<int, pair<int,int>>>q;
	bool clean = false;
	int cnt;
	int x, y;
	visited[start_x][start_y] = true;
	
	q.push({ 0,{ start_x,start_y } });
	box[start_x][start_y] = '.';
	
	while (!q.empty()) {
		cnt = q.front().first;
		x = q.front().second.first;
		y = q.front().second.second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i]; int next_y = y + dy[i];

			if (next_x<1 || next_x>h || next_y<1 || next_y>w) continue;
			if (box[next_x][next_y] == 'x') continue;
			if (visited[next_x][next_y]) continue;
			if (box[next_x][next_y] == '*') {
				for (int i = 0; i < v.size(); i++) {
					if (v[i] == make_pair(next_x, next_y)) {
						dis[c].push_back(cnt);
						dis[i].push_back(cnt);
						box[x][y] = '.';
					}
				}
			}
			q.push({cnt+1, { next_x, next_y }});
			visited[next_x][next_y] = true;
		}
	}

	if (dis[c].size() != v.size() - c-1) {
		cout << -1 <<"\n";
		return;
	}
	else {
		if (c < v.size()-1) {
			robotCleaner(v[c + 1].first, v[c + 1].second, c + 1);
		}
		else {
			permutation(0, 0);
			cout << -pq.top() <<"\n";
			while (!pq.empty()) pq.pop();
			v.clear();
			for (int i = 0; i < 11; i++) {
				dis[i].clear();
			}
		}
	}
}


int main() {
	
	while(1){
		cin >> w >> h;
		if (w == 0 && h == 0) break;
		v.push_back({0,0});
		for (int j = 0; j < h; j++) {
			cin >> str;
			for (int k = 0; k < str.size(); k++) {
				box[j + 1][k + 1] = str[k];
				if (str[k] == 'o') {
					v[0]= { j + 1,k + 1 };
				}
				if (str[k] == '*') v.push_back({j+1, k+1});
			}
		}
		dist = 0;

		robotCleaner(v[0].first, v[0].second, 0);
		
	}
}