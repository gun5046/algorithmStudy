#include <iostream>
#include <vector>
#include <string>
#include <utility>
using namespace std;

string str[5];
bool result = false;
vector<pair<int,int>> p;
void problem(int x, int y, int cnt) {
	if (cnt <= 2) {
		
		if (str[x][y] == 'P') {

		}
	}
	else {
	
	}

}

int main() {
	

	for (int i = 0; i < 5; i++) {
		cin >> str[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (str[i][j] == 'P')
				problem(i, j, 0);
		}
	}
}