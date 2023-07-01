#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <math.h>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>

using namespace std;

int n, m;
int arr[1001], l;
int res=0;

void remainSum() {
	for (int i = 0; i <= 1000; i++) {
		res += arr[i] * (arr[i]-1) / 2;
	}
	res += arr[0];
}


int main() {
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> l;
		sum += l;
		arr[sum%m]++;
	}

	remainSum();
	cout << res;
}