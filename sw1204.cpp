#include <iostream>
#include <vector>
#include <math.h>
#include <utility>
#include <cstring>
#include <algorithm>
using namespace std;
int student[101];
int main() {
	int test;
	cin >> test;

	for (int t = 1; t <= test; t++) {
		cin >> t;
		memset(student, 0, sizeof(student));
		int maximum = 0;
		int idx = 0;
		for (int i = 0; i < 1000; i++) {
			int num;
			cin >> num;
			student[num]++;
		}
		for (int i = 0; i < 101; i++) {
			if (student[i] >= maximum) {
				maximum = student[i];
				idx = i;
			}
		}

		cout << "#" << t << " " << idx << "\n";
	}
}