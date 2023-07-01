#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstring>
#include <string>

using namespace std;

int n;
int l;
int arr[100][100];
int res = 0;
int main() {
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt_h = 1;
		int cnt_l = l;
		int f = 0;
		int val = arr[i][0];
		for (int j = 1; j < n; j++) {
			
			int val2 = arr[i][j];

			if (val2 - val == 0) {
				cnt_h++; cnt_l++;
			}
			else if (val2 - val == 1) {
				if (cnt_h - l < 0) {
					cnt_h = -1;
					break;
				}
				f = 1;
				cnt_h = 1;
				cnt_l = 1;
			}
			else if (val2 - val == -1) {
				if (f == 2) {
					if (cnt_l - l < 0) {
						cnt_h = -1;
						break;
					}
				}
				f = 2;
				cnt_h = 1 - l;
				cnt_l = 1;

			}
			else {
				cnt_h = -1;
				break;
			}
			val = val2;

		}
		if (cnt_h >= 0) {
			res++;
		}
	}

	for (int i = 0; i < n; i++) {
		int cnt_h = 1;
		int cnt_l = l;
		int f = 0;

		int val = arr[0][i];
		for (int j = 1; j < n; j++) {
			int val2 = arr[j][i];
			if (val2 - val == 0) {
				cnt_h++; cnt_l++;
			}
			else if (val2 - val == 1) {
				if (cnt_h - l < 0) {
					cnt_h = -1;
					break;
				}
				f = 1;
				cnt_h = 1;
				cnt_l = 1;
			}
			else if (val2 - val == -1) {
				if (f == 2) {
					if (cnt_l - l < 0) {
						cnt_h = -1;
						break;
					}
				}
				f = 2;
				cnt_h = 1 - l;
				cnt_l = 1;

			}
			else {
				cnt_h = -1;
				break;
			}
			val = val2;

		}
		if (cnt_h >= 0) {
			res++;
		}
	}

	cout << res;
}