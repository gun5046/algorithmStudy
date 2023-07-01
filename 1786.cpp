#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
string str;
string str2;
int cnt = 0;
vector<int>ans;
vector<int> findPattern() {
	int size = str2.length();
	vector<int>pi(size);

	int j = 0;
	for (int i = 1; i < size; i++) {
		while (j > 0 && str2[i] != str2[j]) {
			j = pi[j - 1];
		}

		if (str2[i] == str2[j]) {
			pi[i]=++j;
		}
	}
	return pi;
}

void kmp() {
	int size1 = str.length();
	int size2 = str2.length();

	vector<int> pi = findPattern();
	int j = 0;
	for (int i = 0; i < size1; i++) {
		while (j > 0 && str[i] != str2[j]) {
			j = pi[j-1];
		}
		if (str[i] == str2[j]) {
			if (j == size2 - 1) {
				cnt++;
				ans.push_back(i - j+1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}
}


int main() {
	
	getline(cin, str);
	
	getline(cin, str2);

	kmp();

	cout << cnt << "\n";
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i]<< " ";
	}
}