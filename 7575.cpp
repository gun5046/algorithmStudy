#include <iostream>
#include <vector>
#include <utility>
#include <map>
#define mod 100003
using namespace std;

int n, k;
int m[100];
int a;
vector<int>pr[100];

void virus();
void hashing();
int Mod(long long n) {
	if (n >= 0) return n % mod;
	else return ((-n / mod + 1) * mod + n) % mod;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
		for (int j = 0; j < m[i]; j++) {
			cin >> a;
			pr[i].push_back(a);
		}
	}
	virus();
}

void virus() {
	hashing();
}

void hashing() {

	vector<int>hash_v[100][mod];
	
	for (int t = 0; t < n; t++) {
		int hash = 0;
		int pow = 1;
		for (int i = 0; i + k <= n; i++) {
			if (i == 0) {
				for (int j = 0; j < k; j++) {
					hash = Mod(hash + pr[t][j]*pow);
					if (j < k - 1) pow=Mod(pow * 2);
				}
			}
			else {
				hash = Mod(2*(hash-pr[t][i-1]) + pr[t][i+k-1]);
			}
			if (t == 0) {
				hash_v[0][hash].push_back(i);
			}
			else {
				if (!hash_v[t - 1][hash].empty()) {
					for (int a = 0; a < hash_v[t - 1][hash].size(); a++) {
						bool flag = true;
						for (int b = 0; b < k; b++) {
							if (pr[t-1][hash_v[t - 1][hash][a]+b]!=pr[t][i+b]) {
								flag = false;
								break;
							}
						}
						if (!flag) {
							for (int b = k - 1; b >= 0; b--) {
								if (pr[t - 1][hash_v[t - 1][hash][a] + b] != pr[t][i+b]) {
									flag = false;
									break;
								}
							}
						}
						if (flag) {
							hash_v[t][hash].push_back(i);
						}
					}
				}
			}
		}
	}

	for (int j = 0; j < mod; j++) {
		if (!hash_v[n - 1][j].empty()) {
			cout << "YES";
			break;
			return;
		}
	}
	cout << "NO";
}