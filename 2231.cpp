#include <iostream>
#include <vector>
#include <math.h>
#include <string>
using namespace std;

int main() {

	int n;

	cin >> n;
	int l = 0;
	while (pow(10, l) <= n) {
		l++;
	}
	
	int m = 0;
	int p = l * 9;

	for (int i = p; i > 0; i--) {
		int num = n - i;
		string s = to_string(num);
		int sum = 0;
		for (int j = 0; j < s.size(); j++) {
			sum+=s[j] - '0';
		}
		if (sum == i) {
			cout << num;
			return 0;
		}
	}
	cout << 0;
	return 0;

}