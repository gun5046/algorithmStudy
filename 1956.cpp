#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <sstream>
#include <list>
#include <deque>
#include <math.h>
#include <algorithm>
#include <utility>
#define INF 99999999
using namespace std;

int v, e;

int arr[401][401];
int dist[401][401];
int main() {
	cin >> v >> e;

	for (int i = 0; i < e; i++) {
			int n1, n2, n3;
			cin >> n1 >> n2 >> n3;
			arr[n1][n2] = n3;
	}

	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) dist[i][j] = 0;
			else if (arr[i][j]!=0) {
				dist[i][j] = arr[i][j];
			}
			else {
				dist[i][j] = INF;
			}
		}
	}

	for (int k = 1; k <= v; k++) {
		for (int i = 1; i <= v; i++) {
			for (int j = 1; j <= v; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	int minimum = INF;
	for (int i = 1; i <= v; i++) {
		for (int j = 1; j <= v; j++) {
			if (i == j) continue;
			minimum = min(minimum,dist[i][j] + dist[j][i]);
		}
	}

	if (minimum >= INF) {
		cout << -1;
	}
	else {
		cout << minimum;
	}
}