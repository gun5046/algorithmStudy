#include<iostream>
#include<cstring>
using namespace std;

int dx[2] = { 1,0 };
int dy[2] = { 0,1 };

int n, k;
int cnt;
int map[15][15];


int wordroad(int x, int y, int dir, int c) {

    int nx = x + dx[dir];
    int ny = y + dy[dir];

    if (nx >= n || ny >= n || map[nx][ny] == 0) {
        if (c == k) {
            cnt++;
        }
        return c;
    }

    wordroad(nx, ny, dir, c + 1);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {

        cnt = 0;
        cin >> n >> k;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[i][j] == 1) {
                    int l = wordroad(i, j, 1, 1);
                    j += l - 1;
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (map[j][i] == 1) {
                    int l = wordroad(j, i, 0, 1);
                    j += l - 1;
                }
            }
        }
        cout << "#" << test_case << " " << cnt << "\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

