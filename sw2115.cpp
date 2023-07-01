#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

int test;
int arr[10][10];
int n, m, c;
priority_queue<int>pq;
vector<int>temp;
int big = 0;
int arr2[10][10];
vector<int>set;

void honey(vector<int>v) {
	int total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += v[i];
	}
	if (total > c) return;
	total = 0;
	for (int i = 0; i < v.size(); i++) {
		total += pow(v[i], 2);
	}
	if (big < total) {
		big = total;
	}
}

void powerSet(vector<int>v, int idx) {
	
	if (idx >= v.size()) {
		for (int i = 0; i < set.size(); i++) {
			honey(set);
		}
		return;
	}
	set.push_back(v[idx]);
	powerSet(v, idx + 1);
	set.pop_back();
	powerSet(v, idx + 1);
}

int sol() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			vector<int>v;
			for (int k = j; k <j+ m; k++) {
				v.push_back(arr[i][k]);
			}
			big = 0;
			powerSet(v,0);
			arr[i][j] = big;
			//cout << big << " ";
		}
		//cout << "\n";
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= n - m; j++) {
			int num1 = arr[i][j];
			for (int k = 0; k < n; k++) {
				for (int l = 0; l <= n-m; l++) {
					if (i == k) {
						if (l <= j) {
							if (l + m > j) continue;
						}
						else {
							if (j + m > l) continue;
						}
					}

					int num2 = arr[k][l];
					if (num1 + num2 > answer) {
						answer = num1 + num2;
					}
				}
			}
		}
	}
	return answer;
}

int main() {
	cin >> test;

	for(int t=1; t<=test; t++){
		cin >> n >> m >> c;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
	
		cout <<"#"<<t <<" "<<sol() <<"\n";
	}
}