#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <map>
#include <set>
#include <list>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <stack>
#include <math.h>
#define INF 9999999
using namespace std;

int w,t;
int main() {
	cin >> t;

	for (int test = 0; test < t; test++) {
		vector<int>alpha[26];
		string str;
		cin >> str;
		cin >> w;
		int third = INF;
		int fourth = 0;
		for (int i = 0; i < str.length(); i++) {
			int idx = str[i] - 'a';
			alpha[idx].push_back(i);
		}

		for (int i = 0; i < 26; i++) {
			if (alpha[i].size() < w) continue;
			for (int j = 0; j <= alpha[i].size()-w; j++) {
				int front = alpha[i][j];
				int back = alpha[i][j + w-1];
				third = min(third, back-front+1);
				fourth = max(fourth, back-front+1);
			}
		}
		
		if (third == INF && fourth == 0) {
			cout << -1<<"\n";
		}
		else {
			cout << third << " " << fourth << "\n";
		}
	}
}
