
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int map[7][7][4];
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				int num;
				cin >> num;
				map[i][j][0] = num;
				map[j][n - 1 - i][1] = num;
				map[n - 1 - i][n - 1 - j][2] = num;
				map[n - 1 - j][i][3] = num;
			}
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < n; i++) {
			for (int k = 1; k <= 3; k++) {
				for (int j = 0; j < n; j++) {
					cout << map[i][j][k];
				}
				cout << " ";
			}
			cout << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}