#include <iostream>
#include <cstring>
using namespace std;

int n;
int operands[4];
int num[11];
int maximum = -1000000000, minimum = 1000000000;

void operation(int result, int idx) {
	if (idx == n-1) {
		if (result >= maximum) {
			maximum = result;
		}
		if (result <= minimum) {
			minimum = result;
		}
	}
	else {
		for (int i = 0; i < 4; i++) {
			if (operands[i] != 0) {
				operands[i]--;
				if (i==0) {
					operation(result + num[idx + 1], idx + 1);
				}
				else if(i == 1){
					operation(result - num[idx + 1], idx + 1);
				}
				else if (i == 2) {
					operation(result * num[idx + 1], idx + 1);
				}
				else if (i == 3) {
					operation(result / num[idx + 1], idx + 1);
				}
				
				operands[i]++;
			}
		}
	}
}

int main() {
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	
	for (int i = 0; i < 4; i++) {
		cin >> operands[i];
	}

	operation(num[0],0);
	cout << maximum << '\n'<< minimum;
}