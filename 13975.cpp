#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <utility>

using namespace std;

priority_queue<long long>pq;
int main() {
	int test = 0;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		int k = 0;
		cin >> k;

		for (int i = 0; i < k; i++) {
			int num;
			cin >> num;
			pq.push(-num);
		}
		long long ans=0;
		while (pq.size()>1) {
			long long  n1 = -pq.top();
			pq.pop();
			long long  n2 = -pq.top();
			//cout << n1 << " + " << n2 << " = " << n1 + n2<<"\n";
			pq.pop();
			ans += (n1 + n2);
			//cout << ans << "\n";
			if (!pq.empty()) {
				pq.push(-(n1 + n2));
				//cout << "push : " << n1+n2<<"\n";
			}
		}
		
		if (!pq.empty()) {
			ans += -pq.top();
			pq.pop();
		}

		cout << ans<<"\n";
	}
}

/*1 3 3 4 4 5 5 5 14 17 21 21 32 35 98
3 4 4 4 ~
4 4 5 5 5 7
5 5 5 7 8
5 7 8 10 14 17
8 10 12 14 17
12 14 17 18
17 18 21 21 26
21 21 26 32 35 35 98
26 32 35 35 42 98
35 35 42 58 98
42 58 70 98
70 98 100
100 168
268*/