#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

int t, n, d, c, a, b, s, cnt=0;
int maximum=-1;
vector<pair<int,int>>v[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visited[10001] = { false, };
int computer[10001];
void hacking(int c, int tm) {
	if (tm >= maximum) {
		maximum = tm;
	}
	computer[c] = tm;
	visited[c] = true;
	cnt++;
	int size = v[c].size();
	



	for (int i = 0; i < size; i++) {
		pair<int, int> next = v[c][i];
		if (!visited[next.second]) {
			if (computer[c] + next.first <= computer[next.second]) {
				computer[next.second] = computer[c] + next.first;
				pq.push({ computer[next.second] , next.second });
			}			
		}
	}
	while (!pq.empty()) {
	
		int next_t = pq.top().first;
		int next_comp = pq.top().second;
		pq.pop();
		if (!visited[next_comp]) {
			hacking(next_comp, next_t);
		}

	}
}

int main() {
	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n >> d >> c;
		for (int i = 1; i <= d; i++) {
			cin >> a >> b >> s;
			v[b].push_back({ s, a });
		}
		for (int i = 1; i <= n; i++) {
			computer[i] = 11111111;
		}
		maximum = 0; cnt = 0;
		hacking(c, 0);
		for (int i = 1; i <= n; i++) {
			v[i].clear();
			visited[i] = false;
		}
		
		cout << cnt <<" "<< maximum <<"\n";
		
	}


}