#include <iostream>

using namespace std;

int* num = new int[11001];

int main() {
	for (int i = 1; i <= 10000; i++) {
		num[i] = 0;
	}
	int i = 1;
	int sum;
	int temp;
	while (i <= 10000) {
		sum = i;
		temp = i;
		while (temp != 0) {
			sum +=  temp% 10;
			temp = temp / 10;
		}
		num[sum] = 1;
		++i;
	}

	i = 1;
	while (i <= 10000) {
		if (num[i] == 0) {
			cout << i <<'\n';
		}
		i++;
	}

}

