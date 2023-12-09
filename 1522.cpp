#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main() {
	
	string str;
	cin >> str;
	
	int aCnt = 0;
	int result = 9999;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a')
			aCnt ++;
	}
	str += str;
	for (int i = 0; i < str.size() - aCnt; i++) {
		int change = 0;
		for (int j = i; j < i+aCnt; j++) {
			if (str[j] == 'b')
				change++;
		}
		result = min(result, change);
	}



	cout << result;
}