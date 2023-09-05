#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>

using namespace std;
int arr[50][50];
long long sumArray[50][50];
int n, m;
long long result = 0;
void selectColBox(int x1, int x2) {
	long long a = sumArray[n-1][x1];
	long long b = sumArray[n - 1][x2] - sumArray[n-1][x1];
	long long c = sumArray[n - 1][m - 1] - sumArray[n-1][x2];

	result = max(a * b * c, result);
}
void selectRawBox(int y1,int y2) {
	long long a = sumArray[y1][m-1];
	long long b = sumArray[y2][m-1] - sumArray[y1][m-1];
	long long c = sumArray[n -1][m - 1] - sumArray[y2][m-1];

	result = max(a * b * c, result);
}

void selectBox1(int x, int y) { // で
	long long a = sumArray[y][x];
	long long b = sumArray[y][m - 1] - sumArray[y][x];
	long long c = sumArray[n - 1][m - 1] - sumArray[y][m - 1];

	result = max(a * b * c, result);
}
void selectBox2(int x, int y) { // っ
	long long a = sumArray[y][x];
	long long b = sumArray[n-1][x] - sumArray[y][x];
	long long c = sumArray[n - 1][m - 1] - sumArray[n-1][x];
	
	result = max(a * b * c, result);
}
void selectBox3(int x, int y) { // た
	long long a = sumArray[n-1][x];
	long long b = sumArray[y][m - 1] - sumArray[y][x];
	long long c = sumArray[n - 1][m - 1] - sumArray[y][m - 1] - sumArray[n-1][x] + sumArray[y][x];
	result = max(a * b * c, result);
}
void selectBox4(int x, int y) { // ぬ
	long long a = sumArray[y][m-1];
	long long b = sumArray[n-1][x] - sumArray[y][x];
	long long c = sumArray[n - 1][m - 1] - sumArray[y][m - 1] - sumArray[n-1][x] + sumArray[y][x];
	result = max(a * b * c, result);
}
int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string str;

		cin >> str;

		for (int j = 0; j < m; j++) {
			arr[i][j] = str[j]-'0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int sum = 0;
			if (i > 0) {
				sum += sumArray[i - 1][j];
			}
			if (j > 0) {
				sum += sumArray[i][j - 1];
			}
			if (i > 0 && j > 0) {
				sum -= sumArray[i-1][j - 1];
			}
			sum += arr[i][j];
			sumArray[i][j] = sum;
		}
	}

	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << sumArray[i][j] << " ";
		}
		cout << "\n";
	}*/

	for (int i = 0; i < m-2; i++) {
		for (int j = i+1; j < m -1; j++) {
			selectColBox(i, j);
		}
	}
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			selectRawBox(i, j);
		}
	}
	for (int i = 0; i < m - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			selectBox1(i, j);
			selectBox2(i, j);
			selectBox3(i, j);
			selectBox4(i, j);
		}
	}
	

	cout << result;
}