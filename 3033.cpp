#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <math.h>

using namespace std;

int l;
string s;
int hash1[27];
int n[200000];

void hashing() {
	for (int i = 0; i <= 26; i++) {
		hash1[i] = pow(i + 1, 3);
	}
}
int main() {
	cin >> l;
	cin >> s;

	for (int i = 0; i < l; i++) {

	}
}