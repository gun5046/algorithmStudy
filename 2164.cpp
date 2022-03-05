#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	int goBack;
	cin >> n;
	queue<int> num;
	for (int i = 1; i <= n; i++) num.push(i);

	while (num.size() > 1) {
		num.pop();
		goBack=num.front();
		num.pop();
		num.push(goBack);
	}

	cout << num.front();
}