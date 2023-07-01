#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool arr1[10000];
bool arr2[10000];

int main() {
	int n;
	cin >> n;
	int num;
	int odd=0, even=0;
	vector<bool>v;
	for (int i = 0; i < n; i++) {
		cin >> num;
		if (num % 2 == 0) {
			v.push_back(0);
			even++;
		}
		else {
			v.push_back(1);
			odd++;
		}
	}
	bool flag = false;
	if (abs(even - odd) >= 1) flag = true;
	vector<bool>res1;
	vector<bool>res2;
	int cnt1 = 0;
	int cnt2 = 0;
	if (!flag) {
		for (int i = 0; i < n; i+=2) {
			arr1[i] = 1;
		}
		for (int i = 1; i < n; i += 2) {
			arr2[i] = 1;
		}

		for (int i = 0; i < n; i++) {

			res1.push_back(!(v[i] ^ arr1[i]));
			res2.push_back(!(v[i] ^ arr2[i]));
		}

		for (int i = 0; i < n; i++) {
			if (res1[i] != v[i]) cnt1++;
			if (res2[i] != v[i]) cnt2++;
		}
	}
	if (!flag) {
		if (cnt1 < cnt2) {
			cout << cnt1 / 2 << "\n";
		}
		else {
			cout << cnt2 / 2 << "\n";
		}
	}
	return 0;
}