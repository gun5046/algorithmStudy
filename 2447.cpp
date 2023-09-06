#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;


int n;
char arr[2187][2187];
void makingStar(int m,int x,int y) {
	
	if (m == 1) {
		arr[x][y] = '*';
		return;
	}
	
	for (int i = x; i < x+m; i+=m/3) {
		for (int j = y; j < y+m; j+=m/3) {
			if (m / 3+x <= i && i <= m / 3 * 2 - 1+x && m / 3+y <= j && j <= m / 3 * 2 - 1+y) {
				
			}
			else {
				makingStar(m/3, i, j);
			}
		}
		
	}
	
}

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	
	makingStar(n,0,0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '\0') {
				cout << " ";
			}
			cout << arr[i][j];
		}
		cout << "\n";
	}
}