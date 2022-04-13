#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#define mod 100003
using namespace std;

int l;
string s;
string check;

void longestStr(int start, int end);
int Mod(long long n) {
	if (n >= 0) return n % mod;
	else return ((-n / mod + 1) * mod + n) % mod;
}
int main() {
	cin >> l >> s;
	longestStr(0, s.size() - 1);
}
//길이 이분탐색

void longestStr(int start, int end) {


	bool found = false;
	bool flag = false;
	while (start + 1 < end) {
		long long pow = 1;
		found = false;
		int hash = 0;
		int mid = (start + end) / 2;
		flag = false;
		vector<int>v[mod];
		for (int i = 0; mid + i <= s.size() - 1; i++) {
			if (i == 0) {
				for (int j = 0; j < mid; j++) {
					hash = Mod(hash + s[mid - j - 1] * pow);
					if (j < mid - 1) pow = Mod(pow * 2);
				}
			}
			else {
				hash = Mod(2 * (hash - (s[i - 1] * pow)) + s[mid + i - 1]);
			}
	
			if (v[hash].size() != 0) {
				for (int t : v[hash]) {
					for (int j = 0; j < mid; j++) {
						flag = true;
						if (s[j + t] != s[i + j]) {
							flag = false;
							break;
						}
					}
					if (flag) found = true; break;
				}
			}
			v[hash].push_back(i);
			if (found) break;
		}
		if (found) start = mid;
		else {
			end = mid;
		}
	}
	
	if(!flag)cout << start;
	else {
		cout << end;
	}
}