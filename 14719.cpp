#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int h, w;
vector<int>v[501];
int main() {
	
	cin >> h >> w;

	for (int i = 0; i < w; i++) {
		int floor;
		cin >> floor;

		for (int j = 0; j < floor; j++) {
			v[j].push_back(i);
		}
	}
	int result = 0;
	for (int i = 0; i < h; i++) {
		if (v[i].size() <= 1) continue;
		for (int j = 0; j < v[i].size()-1; j++) {
			int front = v[i][j];
			int back = v[i][j + 1];
			result += back - front - 1;
		}
	}

	cout << result;

}