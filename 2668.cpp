#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int n;
vector<int>v[101];
int arr[101];
bool checked[101];
set<int>s;

void selectNumber(int now,int start, vector<int>v2) {
	
	
	if (checked[now]) {
		if (now == start) {
			for (int a : v2) {
				s.insert(a);
			}
		}
		return;
	}
	checked[now] = true;
	v2.push_back(now);
	selectNumber(arr[now],start,v2);
	checked[now] = false;
	v2.pop_back();
}
int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v[num].push_back(i);
		arr[i] = num;
	}
	for(int i=1; i<=n; i++)
		selectNumber(i, i, {});

	
	set<int>::iterator iter = s.begin();

	cout << s.size()<<"\n";
	for (iter; iter != s.end(); iter++)
		cout << *iter << "\n";

}
