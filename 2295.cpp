#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
#include <set>


using namespace std;
int result = 0;
int main() {
	int n;
	cin >> n;
	set<int>s1;
	set<int>s2;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		s1.insert(num);
	}

	set<int>::iterator iter1;
	set<int>::iterator iter2;
	set<int>::reverse_iterator rit1;
	set<int>::reverse_iterator rit2;

	for (iter1 = s1.begin(); iter1 != s1.end(); iter1++) {
		for (iter2 = s1.begin(); iter2 != s1.end(); iter2++) {
			int sum =*iter1+ *iter2;
			s2.insert(sum);
		}
	}

	for (rit1 = s1.rbegin(); rit1 != s1.rend(); rit1++) {
		for (rit2 = s1.rbegin(); rit2 != s1.rend(); rit2++) {
			int num = *rit1 - *rit2;
			if (s2.find(num) != s2.end()) {
				result = max(result, *rit1);
			}
		}
	}
	cout << result;
}