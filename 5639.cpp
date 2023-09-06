#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <utility>

using namespace std;
vector<int>v;
int root;
vector<int>pre;

void sorRightTree(int idx) {
	if (idx == v.size()) {
		return;
	}

	if (pre[pre.size() - 1] < v[idx]) {
		if (pre[pre.size() - 2] < v[idx]) {
			cout << pre[pre.size() - 1] << "\n";
			cout << v[idx] << "\n";
			pre.pop_back();
		}
		else {
			cout << v[idx] << "\n";
			cout << pre[pre.size() - 1] << "\n";
			pre.pop_back();
		}
	}
	else {
		pre.push_back(v[idx]);
	}
	sorRightTree(idx + 1);
}

void sortLeftTree(int idx) {
	if (idx == v.size()) {
		return;
	}
	if (root < v[idx]) {
		
		int size = pre.size()-1;
		for (int i = size; i > 0; i--) {
			cout << pre[i] << "\n";
			pre.pop_back();
		}
		pre.push_back(v[idx]);
		sorRightTree(idx + 1);
		return;
	}

	if (pre.size()==1) {
		pre.push_back(v[idx]);
		sortLeftTree(idx + 1);
		return;
	}
	
	
	if (pre[pre.size() - 1] < v[idx]) {
		if (pre[pre.size() - 2] < v[idx]) {
			cout << pre[pre.size() - 1] << "\n";
			cout << v[idx] << "\n";
			pre.pop_back();
		}
		else {
			cout << v[idx] << "\n";
			cout << pre[pre.size() - 1] << "\n";
			pre.pop_back();
		}
	}
	else {
		pre.push_back(v[idx]);
	}
	sortLeftTree(idx + 1);
}

int main() {
	int n;
	while (cin >> n) {
		v.push_back(n);
	};

	root = v[0];
	pre.push_back(v[0]);
	sortLeftTree(1);
	int size = pre.size()-1;

	for (int i = size; i >= 0; i--) {
		cout << pre[i] << "\n";
	}

}