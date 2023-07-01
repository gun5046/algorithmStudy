#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	int n, m;
	int num;
	vector<int> v;
	cin >> n >> m;
	int start, end;
	v.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num+v[i]);
	}
	for (int i = 0; i < m; i++) {
		cin >> start >> end;

		cout << v[end] - v[start-1] << "\n";
	}

}