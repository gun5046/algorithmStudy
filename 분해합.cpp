#include <iostream>

#define FIO ios_base :: sync_with_stdio(NULL); cin.tie(); cout.tie();

using namespace std;

int main() {
	FIO;

	int n;

	cin >> n;
	int c=1;
	while (1) {
		int i = 1;
		int x = n /( 10 * i);
		if (x < 1) {
			
			break;
		}
		i = i * 10;
		c++;
	}

	c = c * 9;
	for (int i = n-c; i <= n; i++) {
		
	}
}
