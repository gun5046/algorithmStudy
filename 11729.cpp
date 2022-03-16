#include <iostream>
#include <utility>
#include<queue>
using namespace std;

queue<pair<int, int>>q;
int cnt = 0;

void hanoiTop(int from, int to,int mid, int k);
int main() {
	int k;
	
	cin >> k;
	hanoiTop(1,3,2,k);
	cout << cnt <<'\n';
	while (!q.empty()) {
		cout << q.front().first<<' '<<q.front().second <<'\n';
		q.pop();
	}
}

void hanoiTop(int from, int to, int mid, int k) {
	if (k == 1) {
		q.push(make_pair(from, to));
		cnt++;
	}
	else {
		hanoiTop(from, mid,to, k - 1);
		q.push(make_pair(from, to));
		cnt++;
		hanoiTop(mid, to, from, k - 1);
	}
}


/*
int hanoiTop(int k) {
	if (k == 1) {
		return 1;
	}
	else {
		return 2 * hanoiTop(k - 1) + 1;
	}
}
하노이탑 이동횟수*/