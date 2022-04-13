#include <iostream>
#include <vector>

using namespace std;

string str;
string check;
bool Large(string str, string check);
vector<int>fail(string check);
string st;
int main() {
	cin >> str >> check;

	if (Large(str, check)) {
		cout << 1;
	}
	else {
		cout << 0;
	}
}

bool Large(string str, string check) {
	int ss = str.size();
	int cs = check.size();
	vector<int>pi = fail(check);
	
	bool flag = false;
	for (int i = 0, j = 0; i < ss; i++) {
		if (48 <= str[i] && str[i] <= 57) continue;
		while (j > 0 && str[i] != check[j]) {
			j = pi[j - 1];
		}
		if (str[i] == check[j]) {
			if (j == cs - 1) {
				flag = true;
				break;
			}
			else {
				++j;
			}
		}
	}
	
	return flag;
}

vector<int>fail(string check) {
	int s = check.size();
	vector<int>pi(s);
	for (int i = 1, j = 0; i < s; i++) {
		while (j > 0 && check[i] != check[j]) {
			j = pi[j - 1];
		}
		if (check[i] == check[j]) {
			pi[i]=++j;
		}
	}
	return pi;
}