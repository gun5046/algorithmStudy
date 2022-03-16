#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int t;
int n;
pair<int, int>store[101];
pair<int, int>home;
pair<int, int>festival;
void goFestival(int x, int y, int distance, int beer) {

}


int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cin >> home.first >> home.second;
		cout << home.first << home.second;
		for (int j = 1; j <= n; j++) {
			cin >> store[j].first >> store[j].second;
		}
		cin >> festival.first >> festival.second;
		goFestival(home.first,home.second,0, 20);
	}
}