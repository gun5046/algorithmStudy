#include <iostream>
#include <vector>

using namespace std;
string s;
string c;
vector<int>Fail(string pattern);
vector<int>KMP(string pattern, string text);
int main() {
	cin >> s >> c;
	vector<int>answer = KMP(s, c);
	for (int a : answer) {
		cout << a;
	}
}

vector <int> KMP(string pattern, string text) {
	int m = pattern.length();
	int n = text.length();

	vector<int>pos; // 검색에 성공한 위치 position에 저장
	vector<int>pi = Fail(pattern); //pi 배열 구하기

	for (int i = 0, j=0; i < n; i++) {
		while (j>0 && text[i] != pattern[j])
		{
			j = pi[j - 1];
		}
		if (text[i] == pattern[j]) {
			if (j == m - 1) {
				pos.push_back(i - m + 1);
				j = pi[j];
			}
			else j++;
		}
	}
	return pos;
}

vector<int> Fail(string pattern) {
	int m = pattern.length();
	vector<int>pi(m);
	string check = pattern;
	for (int i = 1 , j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != check[j]) {
			j = pi[j - 1];
		}
		if (pattern[i] == check[j]) {
			pi[i] = ++j;
		}
	}
	return pi;
}