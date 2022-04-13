#include <iostream>
#include <math.h>
using namespace std;

int x;
int main() {
	cin >> x;
	int cnt=0;
	for (int i = 6; i >= 0; i--) {
		int a = x & 1;
		if (a == 1) cnt++;
		x= x >> 1;
	}
	cout << cnt;
}
