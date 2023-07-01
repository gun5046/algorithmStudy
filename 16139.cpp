#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int arr[200001][26];
int sum[26];
int main() {
	string str;
	int q;
	ios::sync_with_stdio(false);

	cin.tie(NULL);

	cout.tie(NULL);
	cin >> str;
	cin >> q;
	
	int s, e;
	char c;
	for (int i = 1; i <= str.size(); i++) {
		int idx = str[i-1] - 'a';
		sum[idx]++;
		for (int j = 0; j < 26; j++) {
			arr[i][j] = sum[j];
		}
	}

	for (int i = 0; i < q; i++) {
		cin >> c >> s >> e;

		cout << arr[e+1][c-'a'] - arr[s][c-'a'] << "\n";
		
	}
}