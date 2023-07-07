#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <utility>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <time.h>
#include <list>
#include <deque>
#include <sstream>


using namespace std;

int n;
int arr[200];
int dp[200];
int result=0;
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		arr[i] = num;
	}
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
				dp[i] = dp[j] + 1;
			}
		}
		result = max(dp[i], result);
	}

	cout << n - result;
}




// LIS  ÃÖÁ¾

//int n;
//int arr[100000];
//vector<int> index;
//vector<int>v;
//
//int binary_search(int start, int end, int num) {
//
//	while (start < end) {
//		int mid = (start + end) / 2;
//		if (v[mid] < num) {
//			start = mid+1;
//		}
//		else {
//			end = mid;
//		}
//	}
//	return end;
//}
//
//int main() {
//	cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int num;
//		cin >> num;
//		arr[i] = num;
//	}
//
//	v.push_back(arr[0]);
//	index.push_back(0);
//	for (int i = 1; i < n; i++) {
//		if (v.back() < arr[i]) {
//			v.push_back(arr[i]);
//			index.push_back(v.size()-1);
//		}
//		else {
//			int idx = binary_search(0,v.size()-1, arr[i]);
//			v[idx] = arr[i];
//			index.push_back(idx);
//		}
//	}
//	cout << v.size()<<"\n";
//
//	for (int i = 0; i < index.size(); i++) {
//		cout << index[i]<<" ";
//	}
//}