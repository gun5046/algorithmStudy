#include <iostream>
#include <vector>

using namespace std;
int n;
int m;
int column;
int row;
int box[1001][1001];
void bSum(int x1, int y1, int x2, int y2) {

}

int main() {
	cin >> n>> m;
	int num;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> num;
			box[i][j] = box[i][j - 1];
		}
	}
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= n; i++) {
			box[i][j] = box[i-1][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int c, x1, y1, x2, y2, w;
		cin >> w;
		if (w == 1) {
			cin >> x1, y1, x2, y2;	
//			bSum(x1, y1,x2,y2);
		}
		else {

		}
	}
}