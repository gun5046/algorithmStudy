#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>v;
vector<int>v1;
int bigTree;
int main() {

	int test = 0;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		int n;
		v.clear();
		v1.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		bigTree = v[v.size() - 1];
		int temp = 0;
		for (int i = 0; i < n - 1; i++) {
			temp += (bigTree - v[i]) / 3; // 12 12 12
			v1.push_back((bigTree - v[i]) % 3);
		}
		int answer = 0;

		answer += temp * 2;
		int one = 0, two = 0;
		for (int i = 0; i < n - 1; i++) {
			if (v1[i] == 1) {
				one++;
			}
			else if (v1[i] == 2) {
				two++;
			}
		}
		if (one >= two) {
			answer += two * 2;
			answer -= 1;
		}
		else {
			answer += one * 2;
		}

		answer += abs(one - two) * 2;
		cout << answer;
	}
}