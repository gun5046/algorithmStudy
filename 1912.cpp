#include <iostream>
#include <vector>

using namespace std;


int n;
int arr[100000];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int big = -1000;
	for (int i = 0; i < n; i++) {
		sum += arr[i];    // 10 -4 6
		if (big <= sum) {
			big = sum;
			if (sum < 0)
				sum = 0;
		}
		else {
			if (sum >= 0) {
				continue;
			}
			sum = 0;
		}
	}

	cout << big;
}