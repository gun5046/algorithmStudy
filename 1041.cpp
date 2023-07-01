#include <vector>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

long long  n, arr[6];
priority_queue <long long>pq;
int main() {
	cin >> n;

	for (long long i = 0; i < 6; i++) {
		cin >> arr[i];
	}
	
	if (arr[0] < arr[5]) {
		pq.push(-arr[0]);
	}
	else {
		pq.push(-arr[5]);
	}
	if (arr[1] < arr[4]) {
		pq.push(-arr[1]);
	}
	else {
		pq.push(-arr[4]);
	}
	if (arr[2] < arr[3]) {
		pq.push(-arr[2]);
	}
	else {
		pq.push(-arr[3]);
	}
	long long  m[3];
	for (long long i = 0; i < 3; i++) {
		m[i] = -pq.top(); pq.pop();
	}
	if (n == 1) {
		long long max1 = 0;
		int sum2 = 0;
		for (int i = 0; i < 6; i++) {
			if (arr[i] > max1) {
				max1 = arr[i];
			}
			sum2 += arr[i];
		}
		sum2 -= max1;
		cout << sum2;
		return 0;
	}
	
	long long a= (m[0] + m[1] + m[2]) * 4;
	long long b= ((n - 2) * 4 + (n - 1) * 4) * (m[1] + m[0]);
	long long c= ((n - 2) * 4 + ((n - 2) * (n - 2) * 5)) * m[0];
	long long sum = a + b + c;
	cout << sum;
	return 0;
}