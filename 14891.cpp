#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <sstream>
#include <bitset>

using namespace std;
int arr[4];

void turnRight(int x, int d) {
	int data;
	if (d == 1) {
		int c = (int)pow(2, 0) & arr[x];
		data = arr[x] >> 1;
		data |= (c << 7);
	}
	else {
		int c = (int)pow(2, 7) & arr[x];

		data = arr[x] << 1;
		data |= (c>>7);

	}

	if (x == 3) {
		arr[x] = data;
		return;
	}

	bool a = ((arr[x] & (int)pow(2, 5)) == pow(2, 5));
	bool b = ((arr[x + 1] & (int)pow(2, 1)) == pow(2, 1));
	

	if (!(a ^ b)) {
		arr[x] = data;
		return;
	}
	arr[x] = data;

	turnRight(x + 1, d * -1);
}
void turnLeft(int x, int d) {
	int data;
	if (d == 1) {
		int c = (int)pow(2, 0) & arr[x];

		data = arr[x] >> 1;
		data |= (c << 7);

	}
	else {

		int c = (int)pow(2, 7) & arr[x];

		data = arr[x] << 1;
		data |= (c>>7);

	}
	if (x == 0) {
		arr[x] = data;
		return;
	}
	bool a = ((arr[x] & (int)pow(2, 1)) == pow(2, 1));
	bool b = ((arr[x - 1] & (int)pow(2, 5)) == pow(2, 5));

	if (!(a ^ b)) {
		arr[x] = data;
		return;
	}
	arr[x] = data;

	turnLeft(x - 1, d * -1);
}

int main() {
	string str;

	for (int i = 0; i < 4; i++) {
		cin >> str;

		for (int j = 0, k = 7; j < 8; j++, k--) {
			if (str[j] == '1') {
				arr[i] += pow(2, k);
			}
		}
	}

	int k;
	cin >> k;

	for (int i = 0; i < k; i++) {
		int x;
		int d;
		cin >> x >> d;
		
		if (x == 1) {
			turnRight(x - 1, d);
		}
		else if (x == 4) {
			turnLeft(x - 1, d);
		}
		else {

			turnRight(x - 1, d);
			if (d == 1) {
				int c = (int)pow(2, 7) & arr[x-1];
				int data = arr[x-1] << 1;
				data |= (c>>7);
				arr[x-1] = data;

			}
			else {
				int c = (int)pow(2, 0) & arr[x-1];

				int data = arr[x-1] >> 1;
				data |= (c << 7);
				arr[x-1] = data;
			}

			turnLeft(x - 1, d);
		}
	}
	int res = 0;
	for (int i = 0; i < 4; i++) {
		if (arr[i] & (int)pow(2, 7)) {
			res += pow(2, i);
		}
	}
	cout << res;
}