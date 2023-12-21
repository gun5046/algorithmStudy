#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <cstring>
#include <string>
using namespace std;
int n1,x1, k, p;
string n;
string x;
int result = 0;
bool num[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1}
};

void switchLcd(int idx,int change, string changeStr) {
	if (idx >= k) {
		return;
	}
	for (int i = 0; i <= 9; i++) {
		if (i == changeStr[idx]-'0') continue;
		
		int switchCnt = 0;
		for (int j = 0; j < 7; j++) {
			if (num[i][j] ^ num[changeStr[idx]-'0'][j]) {
				switchCnt++;
			}
		}
		
		if (switchCnt > change) continue;
		string temp = changeStr;
		temp[idx] = i+'0';

		if (stoi(temp) > stoi(n)) continue;
		
		if (switchCnt > 0) {
			result++;
			switchLcd(idx + 1, change - switchCnt,temp);
		}
		else {
			switchLcd(idx + 1, change, temp);
		}
		
	}
}

int main() {
	cin >> n >> k >> p >> x;
	string temp="";
	for (int i = 0; i < k-n.length(); i++) {
		temp += '0';
	}
	n = temp + n;
	temp = "";
	for (int i = 0; i < k - n.length(); i++) {
		temp += '0';
	}
	x = temp + x;
	switchLcd(0, p, x);

	cout << result;
}