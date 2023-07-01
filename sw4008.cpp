#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <cstring>
#include <string>
#include <list>
#include <utility>
#define INF 999999999
using namespace std;

int n;
int p, s, m, d;
int arr[12];
int big = -INF;
int small = INF;
int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		big = -INF;
		small = INF;
		cin >> n;

		cin >> p >> s >> m >> d;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		char op[11];
		int idx = 0;
		for (int i = 0; i < m; idx++, i++) {
			op[idx] = '*';
		}
		for (int i = 0; i < p; idx++, i++) {
			op[idx] = '+';
		}
		for (int i = 0; i < s; idx++, i++) {
			op[idx] = '-';
		}
		for (int i = 0; i < d; idx++, i++) {
			op[idx] = '/';
		}

		do {
			int num = arr[0];
			/*for (int i = 0; i < n - 1; i++) {
				cout << op[i]<< " ";
			}
			cout << "\n";*/
			for (int i = 1; i < n; i++) {
				switch (op[i - 1])
				{
				case '+':
					num += arr[i];
					break;
				case '-':
					num -= arr[i];
					break;
				case '*':
					num *= arr[i];
					break;
				case '/':
					num /= arr[i];
					break;
				}
			}
			/*cout << num << "\n";*/
			if (big < num) {
				big = num;
			}
			if (small > num) {
				small = num;
			}

		} while (next_permutation(op, op + (n - 1)));

		cout << "#" << t << " " << big - small << "\n";
	}
}