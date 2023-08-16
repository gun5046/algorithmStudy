#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <algorithm>
#include <math.h>
#include <sstream>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

int n, k;

class Belt {
public :
	deque <pair<int,int>> d;
	int zero = 0;
	deque<int>robot;
	void rotate() {
		int end_num = d[d.size() - 1].second;
		d.pop_back();
		d.push_front({ 0,end_num });
		d[d.size() - 1].first = 0;
		int size = robot.size();
		for (int i = 0; i < robot.size(); i++) {
			if (++robot[i] == n-1) {
				d[robot[i]].first = 0;
				robot.pop_front();
				i--;
			}
		}
	}
	void movingRobot() {
		for (int i = 0; i < robot.size(); i++) {
			if (d[robot[i] + 1].second >= 1 && d[robot[i]+1].first != 1) {
				d[robot[i]].first = 0;
				if (--d[robot[i] + 1].second == 0) {
					zero++;
				}

				if (++robot[i] == n - 1) {
					d[robot[i]].first = 0;
					robot.pop_front();
				}
				else {
					d[robot[i]].first = 1;
				}
				
			}
		}

		if (d[0].second >= 1) {
			robot.push_back(0);
			if (--d[0].second == 0) {
				zero++;
			}
			d[0].first = 1;
		}
	}
	bool confirmZero() {
		if (zero >= k) {
			return false;
		}
		return true;
	}
};
int main() {
	cin >> n;
	cin >> k;

	Belt belt;
	for (int i = 0; i < 2 * n; i++) {
		int num;
		cin >> num;
		belt.d.push_back({ 0,num });
	}
	int cnt = 0;
	while (belt.confirmZero()) {
		belt.rotate();
		belt.movingRobot();
		cnt++;
	}

	cout << cnt;
}