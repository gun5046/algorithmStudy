#include <vector>
#include <iostream>
#include <queue>
#include <utility>
#define ll long long
using namespace std;
ll n;
ll dis[99999];
ll price[100000];
ll sum[100000];
int main() {

	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;

	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> dis[i];
		sum[i + 1] = sum[i] + dis[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> price[i];
		pq.push({ price[i],i });
	}
	ll t = n - 1;
	ll res = 0;
	while (!pq.empty()) {
		ll idx = pq.top().second;
		ll p = pq.top().first;
		pq.pop();

		if (idx < t) {
			res += (sum[t] - sum[idx]) * p;
			t = idx;
		}
		if (idx == 0) {
			break;
		}
	}

	cout << res;
}