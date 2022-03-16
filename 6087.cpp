#include <iostream>
#include <string>
#include <vector>
#include <queue>
#define MAX 99999
using namespace std;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

int h, w;
char box[101][101];
int res[101][101];
vector<pair<int, int>>raser;
string str;
queue<pair<pair<int, int>, pair<int, int>>> q;

void raserComm(int first_x, int first_y) {
	q.push({ { first_x, first_y }, { 5,0 } });
	res[first_x][first_y] = 0;
	while (!q.empty())
	{

		int x = q.front().first.first;
		int y = q.front().first.second;
		int dir = q.front().second.first;
		int mir = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			int nmir = mir;
			if (next_x >= 1 && next_x <= h && next_y <= w && next_y >= 1) {
				if (box[next_x][next_y] != '*') {
					if (dir != i && dir != 5) {
						nmir += 1;
					}
					if (res[next_x][next_y] >= nmir) {
						res[next_x][next_y] = nmir;
						q.push({ {next_x, next_y},{i, nmir} });
					}
				}
			}
		}
	}
	cout << res[raser[1].first][raser[1].second];
}


int main() {

	cin >> w >> h;

	for (int i = 0; i < h; i++) {
		cin >> str;
		for (int j = 0; j < w; j++) {
			box[i + 1][j + 1] = str[j];
			if (str[j] == 'C') {
				raser.push_back({ i + 1,j + 1 });
			}
			res[i + 1][j + 1] = MAX;
		}
	}
	raserComm(raser[0].first, raser[0].second);
}