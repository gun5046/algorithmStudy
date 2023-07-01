#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
#include <set>
#include <stack>

using namespace std;

int main() {
	int n, num1, num2;
	cin >> n;
	set<pair<int,int>>s;
	int back=0, room =1;
	for (int i = 0; i < n; i++) {
		cin >> num1 >> num2;
		s.insert({num1, num2});
	}
	set<pair<int, int>>::iterator iter;
	
	cout << room;
}