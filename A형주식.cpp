#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>

using namespace std;
int arr[15][16];
vector<int>sell;
int onlyMa=0;
int main() {
	int ms,ma, d, l;

	cin >> ms >> ma >> d >> l;

	for (int i = 0; i < d; i++) {
		for (int j = 0; j < l+1; j++) {
			cin >> arr[i][j];
		}
	}
	onlyMa = ms + ma * (l - 1);

	for (int i = 0; i < l; i++) {
		if (i != 0) {
			ms += ma;
			cout << "MA값 추가  " << ms - ma << "->" << ms<<"\n";
		}

		for (int j = sell.size()-1; j >= 0; j--) {
			ms+=sell[j];
			cout << "매도  " << sell[j] << "\n";
			sell.pop_back();
		}
		cout << "남은돈  " << ms << "\n";
		priority_queue<pair<pair<int, int>, int>>pq;
		for (int j = 0; j < d; j++) {
			int m=arr[j][i];
			int nm = arr[j][i+1];

			pq.push({ { nm - m, -m }, nm });
		}

		while (!pq.empty() &&  pq.top().first.first > 0) {
			int nm = pq.top().second;
			int m = -pq.top().first.second;
			pq.pop();
			if (ms / m < 1) break;
			sell.push_back(ms / m *nm);
			cout << "매매 " << m << " 을 " << ms / m << " 개 " << "\n";
			ms%= m;
			
		}
		cout << "남은돈  " << ms << "\n";
	}
	ms += ma;
	cout << "MA값 추가  " << ms - ma << "->" << ms << "\n";
	for (int i = 0; i < sell.size(); i++) {
		ms += sell[i];
		cout << "매도  " << sell[i] << "\n";
		sell.pop_back();
	}

	cout << ms - onlyMa;
}
/*
400 20 3 6
100 100 90 120 140 150 70
50 100 70 100 200 100 30
20 40 10 10 30 50 20
*/