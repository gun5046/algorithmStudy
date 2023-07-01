#include <iostream>
#include <vector>

using namespace std;



int arr[1025][1025];

int main() {
	int n, m;
	int x1, x2, y1, y2;
	int num;
	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		arr[0][i] = 0;
		arr[i][0] = 0;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> num;
			arr[i + 1][j + 1] = arr[i][j+1] + arr[i+1][j]-arr[i][j] + num;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x1 >> y1 >> x2 >> y2;

		int sum = arr[x2][y2] - arr[x2][y1-1] - arr[x1-1][y2]+arr[x1-1][y1-1];


		cout << sum<<"\n";
	}


}