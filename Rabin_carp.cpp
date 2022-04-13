#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
void findString(string parent, string pattern);
int main() {
	string parent = "ababacabacaabacaaba";
	string pattern = "abacaaba";
	findString(parent, pattern);
	return 0;
}

void findString(string parent, string pattern) {
	int parentSize = parent.length();
	int patternSize = pattern.length();
	int parentHash = 0;
	int patternHash = 0;
	int power = 1;

	for (int i = 0; i <= parentSize - patternSize; i++) {
		if (i == 0) {
			for (int j = 0; j < patternSize; j++) {
				parentHash = parentHash + parent[patternSize - 1 - j] * power;
				patternHash = patternHash + pattern[patternSize - 1 - j] * power;
				
				if (j < patternSize - 1) power = power * 2;
			}
		}
		else {
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}

		if (parentHash == patternHash) {
			bool finded = true;
			for (int j = 0; j < patternSize; j++) {
				if (parent[i + j] != pattern[j]) {
					finded = false;
					break;
				}
			}
			if (finded) {
				cout << i+1<<"¹ß°ß";
			}
		}

	}
}