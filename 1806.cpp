#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;

int main() {
	int n, s;
	vector<int> part_sum;
	cin >> n >> s;
	int num1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> num1;

		sum += num1;
		part_sum.push_back(sum);
		
	}

	int back=-1;
	int len;
	for (int i = 0; i < part_sum.size(); i++) {
		if (part_sum[i] < s) continue;
		else {
			len = i+1;
			back = i;
			break;
		}
	}
	if (back == -1) {
		cout << 0;
	}
	else {
		int start = 0;
		for (back; back < part_sum.size(); back++) {
			if (part_sum[back] - part_sum[start] < s) continue;
			for (start; start < back; start++) {
				if (part_sum[back] - part_sum[start] >= s) {
					if (back - start < len) {
						len = back - start;
					}
				}
				else {
					break;
				}
			}
		}
		cout << len;
	}

	
}



