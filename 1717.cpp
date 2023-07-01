#include <iostream>
#include <vector>
#include <sstream>
#include <string>


using namespace std;

int n, m;

int parent[1000001];
int find(int x) {
	if (parent[x] == x) {
		return x;
	}
	else {
		return parent[x]=find(parent[x]);
	}
}
void Union(int x, int y) {
	int nx = find(x);
	int ny = find(y);


	if (nx > ny) {
		parent[nx] = ny;
	}
	else if (ny > nx) {
		parent[ny] = nx;
	}
}



int main() {
	cin >> n >> m;
	cin.ignore();
	for (int i = 0; i <= n; i++) {
		parent[i] = i;
	}

	for (int i = 0; i < m; i++) {
		string str1; string str2;
		string str3;
		
		cin >> str1 >> str2 >> str3;
		int x = stoi(str2);
		int y = stoi(str3);
		if (str1 == "0") {
			Union(x, y);
		}
		else {
			int x_root = find(x);
			int y_root = find(y);
			if (x_root == y_root) {
				cout << "YES" << "\n";
			}
			else {
				cout << "NO" << "\n";
			}
		}

	}
}