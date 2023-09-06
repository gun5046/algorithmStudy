#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;

int input[3];
int n;
int cube[21];
int cnt = 0;
int result = 0;
void fillBox(int x,int y, int z) {
	if (cube[0] == 0) {
		result = -1;
		cout << "-1" << "\n";
		return;
	}
	int power = 20;
	while (min(x,y,z) < pow(2, power)) {
		power--;
	}
	
	
	if (x==y && y==z && x == pow(2, power)) {
		/*if (z / pow(2, power) == 0) {
			for (int i = 0; i < 8; i++) {
				fillBox(x / 2, y / 2, z);
			}
		}*/
		if (z / pow(2, power) > cube[power]) {
			result += cube[power];
			int left = z / pow(2, power) - cube[power];
			cube[power] = 0;
			for (int i = 0; i < 8*left; i++) {
				fillBox(x / 2, y / 2, x/2);
			}
			return;
		}
		else {
			result += z / pow(2, power);
			cube[power] -= z / pow(2, power);
			cnt++;
			if (cnt == 1100) {
				cout << "";
			}
			return;
		}
	}
	else {
		if (min(x, y, z) == x) {
			fillBox(pow(2, power), pow(2, power), z);
			if (x - pow(2, power) > 0) {
				fillBox(x - pow(2, power), pow(2, power), z);
			}
			if (y - pow(2, power) > 0) {
				fillBox(pow(2, power), y - pow(2, power), z);
			}
			if (x - pow(2, power) > 0 && y - pow(2, power) > 0) {
				fillBox(x - pow(2, power), y - pow(2, power), z);
			}

		}
		else if(min(x,y,z == y)){
			fillBox(pow(2, power), pow(2, power), z);
			if (x - pow(2, power) > 0) {
				fillBox(x - pow(2, power), pow(2, power), z);
			}
			if (y - pow(2, power) > 0) {
				fillBox(pow(2, power), y - pow(2, power), z);
			}
			if (x - pow(2, power) > 0 && y - pow(2, power) > 0) {
				fillBox(x - pow(2, power), y - pow(2, power), z);
			}

		}
		else {
			fillBox(pow(2, power), y, pow(2,power));
			if (z - pow(2, power) > 0) {
				fillBox(pow(2, power), y, z-pow(2, power));
			}
			if (x - pow(2, power) > 0) {
				fillBox(x-pow(2, power), y, pow(2, power));
			}
			if (z - pow(2, power) > 0 && x - pow(2, power) > 0) {
				fillBox(x - pow(2, power), y, z-pow(2,power));
			}

		}
		
		
	}
}

int main() {
	cin >> input[0] >> input[1] >> input[2];

	sort(input, input + 3);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		cube[n1] = n2;
	}

	fillBox(input[0], input[1], input[2]);
	cout << result;
}