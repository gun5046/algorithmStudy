#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, a, b, c;
	int p=0;
	cin >> n;
	vector <int> v;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	cin >> b >> c;

	p += n;

	for (int i = 0; i < n; i++) {
		int temp = v[i] - b;
		if (temp % c == 0) {
			p+=temp / c;
		}
		else {
			p += temp / c + 1;
		}
	}

	cout << p;
}