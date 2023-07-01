#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <string>
using namespace std;

int test;

vector<string> split(string str, int n) {
	vector<string>v;
	for (int i = 0; i < str.length(); i += n) {
		v.push_back(str.substr(i,n));
	}
	return v;
}

vector<long long> transform(vector<string> str) {
	vector<long long>v;
	for (int i = 0; i < 4; i++) {
		int p=0;
		long long num=0;
		for (int j = str[i].size()-1; j >= 0; j--) {
			int c = (str[i][j] - '0');
			if (c<10) {
				num+=c*pow(16, p++);
			}
			else {
				num += (str[i][j] - 'A' + 10) * pow(16, p++);
			}
		}
		v.push_back(num);
	}
	return v;
}

string shift(string str) {
	char temp=str[str.size()-1];
	for (int i = str.size() - 1; i >= 1 ; i--) {
		str[i] = str[i - 1];
	}
	str[0] = temp;

	return str;
}
int main() {
	cin >> test;

	for (int t = 1; t <= test; t++) {
		int n, k;
		cin >> n >> k;
		string str;
		cin >> str;
		set<long long>s;
		for (int i = 0; i < n / 4; i++) {
			vector<string>list = split(str,n/4);
			vector<long long> v = transform(list);
			for (int j = 0; j < 4; j++) {
				s.insert(-v[j]);
			}
			str = shift(str);
		}

		set<long long> ::iterator iter = s.begin();
		int cnt = 1;
		for (iter; iter != s.end(); iter++) {
			if (cnt++ == k) {
				cout << "#" << t << " " << -*iter<<"\n";
				break;
			}
		}
	}
}