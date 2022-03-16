#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
long long **mat;
long long b;
long long **res;
long long **temp;

void multiplyMat(long long **m1, long long **m2) {
	long long retMat[5][5];

	long long t;
	memset(retMat, 0, sizeof(retMat));
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				 t = (m1[i][k]*m2[k][j])%1000;
				retMat[i][j] += t;
			}
			retMat[i][j] %= 1000;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			m1[i][j] = retMat[i][j];
		}
	}
}

void matSquare(long long a) {
	if (a <= 1) {
		multiplyMat(res, mat);
	}
	else {
		if (a % 2 == 1) {
			multiplyMat(res, mat);
		}
		multiplyMat(mat, mat);
		matSquare(a/2);
	}
}



int main() {
	cin >> n >> b;
	mat = new long long *[n];
	res = new long long* [n];
	temp = new long long * [n];
	for (int i = 0; i < n; i++) {
		res[i]=new long long [n];
		mat[i] = new long long [n];
		temp[i] = new long long[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			res[i][j] = 0;
		}
		res[i][i] = 1;
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			temp[i][j] = mat[i][j];
		}
	}
	matSquare(b);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << res[i][j] << " ";
		}
		cout << "\n";
	}
}