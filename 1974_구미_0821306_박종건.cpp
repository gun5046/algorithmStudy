
#include<iostream>

using namespace std;
int map[9][9];

bool sudoku() {
	for (int i = 0; i < 9; i++) {
		int row_sum=0;
		for (int j = 0; j < 9; j++) {
			row_sum += map[i][j];
		}
		if (row_sum != 45) {
			return 0;
		}
	}

	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			int square_sum=0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					square_sum+=map[(m*3)+i][(n*3)+j];
				}
			}
			if (square_sum != 45) {
				return 0;
			}
		}
	}

	for (int i = 0; i < 9; i++) {
		int row_sum = 0;
		for (int j = 0; j < 9; j++) {
			row_sum += map[j][i];
		}
		if (row_sum != 45) {
			return 0;
		}
	}
	return 1;
}
int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cin >> map[i][j];
			}
		}
		
		cout << "#" << test_case << " "<< sudoku() << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}