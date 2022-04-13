#include <iostream>
#include <vector>

using namespace std;

string s, p;
vector<int>kmp(string s, string pattern);
vector<int>fail(string pattern);
int main() {
	cin >> s >> p;
	if (kmp(s, p).size() == 0) {
		cout << 0;
	}
	else {
		cout << 1;
	}
}

vector<int>kmp(string s, string pattern) {
	int s_size = s.size();
	int p_size = p.size();
	vector<int>pi = fail(pattern);
	vector<int>pos;
	for (int i = 0, j = 0; i < s_size; i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == p_size - 1) {
				pos.push_back(i);
				j = pi[j];
			}
			else {
				++j;
			}
		}
	}
	return pos;
}

vector<int>fail(string p) {
	int size = p.size();
	vector<int>pi(size);
	
	for (int i = 1, j = 0; i < size; i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j-1];
		}
		if (p[i] == p[j]) {
			pi[i]=++j;
		}
	}

	return pi;
}