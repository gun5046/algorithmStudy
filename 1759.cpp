#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int l, c;
char ch[15];
bool visit[15];
vector<char>v;
void alpha(int depth, vector<char>v1, int x, int y, int start) {
	if (depth == l) {
		if (x >= 1 && y >= 2) {
			for (char c : v1) {
				cout << c;
			}
			cout << "\n";
		}
		return;
	}

	for (int i = start; i < c; i++) {
		//if (visit[i]) continue;
		int nx = x;
		int ny = y;
		
		if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u') {
			nx += 1;
		}
		else {
			ny += 1;
		}
		//visit[i] = true;
		v1.push_back(ch[i]);
		alpha(depth+1, v1, nx,ny,i+1);
		v1.pop_back();
		//visit[i] = false;
	}
}
int main() {
	
	cin >> l >> c;
	
	for (int i = 0; i < c; i++) {
		char c1;
		cin >> c1;
		ch[i] = c1;
	}
	
	sort(ch, ch + c);
	vector<char>v1;
	alpha(0,v1,0,0,0);
}