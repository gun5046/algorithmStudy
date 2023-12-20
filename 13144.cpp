#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <list>
#include <deque>
#include <string>
#include <cstring>

using namespace std;


long long  n;
long long total = 0;
vector<int>v;
int arr[100001];
int main() {
	cin >> n;

	total = n * (n + 1) / 2;
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num;
		v.push_back(num);
	}

	long long distract = 0;
	for (int front = 0, back = 0; back < n;) {
		if (arr[v[back]] == 1) {
			long long add = 1;
			while (v[front++] != v[back]) {
				arr[v[front-1]]--;
				add++;
			}
			distract += (n - back)*(add);
		}
		else {
			arr[v[back]]++;
		}
		back++;
	}

	total -= distract;
	cout << total;

}