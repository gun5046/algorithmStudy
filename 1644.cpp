#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <math.h>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;
const int MAX = 4000000;
vector<int>v;
bool arr[4000001];
int n;
int res=0;
void sosu() {

	for (int i = 2; i * i <=n; i++) {
		if (arr[i]) continue;
		for (int j = i*i; j <= n; j += i) {
			arr[j] = true;
		}
	}
	int sum = 0;
	v.push_back(0);
	for (int i = 2; i <= n; i++) {
		if (!arr[i]) {
			sum += i;
			v.push_back(sum);
		}
	}
}

int main() {
	
	
	cin >> n;
	sosu();
	
	for (int back = 0, front = 1; front < v.size();) {
	
		if (v[front] - v[back] == n) {
			res++;
		}
		
		if (v[front] - v[back] <= n) {
			front++;
		}
		else {
			back++;
		}
	}

	cout << res;
}