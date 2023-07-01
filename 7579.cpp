#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <string>
#include <utility>

using namespace std;

int n, m;
vector<int>app;
vector<int>memory;

void sol() {

}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		app.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		memory.push_back(num);
	}

	sol();
}