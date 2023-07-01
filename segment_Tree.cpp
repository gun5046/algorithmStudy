#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>
#include <deque>
#include <list>
#include <bitset>
using namespace std;

int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
class sTree { // ±¸°£ÇÕ
public :
	int n;
	vector<int>tree;

	int merge(int left, int right) {
		return left + right;
	}

	void build(int size) {
		this->n = size;
		this->tree.resize(n*4);
	}

	int set(int *arr, int node, int node_left, int node_right) {
		if (node_left == node_right) {
			tree[node] = arr[node_left];
			return tree[node];
		}
		int mid = node_left + (node_right - node_left) / 2; // (node_left+node_right)/2
		int left_v = set(arr, node * 2, node_left, mid);
		int right_v = set(arr, node * 2 + 1, mid + 1, node_right);

		tree[node] = merge(left_v, right_v);
		return tree[node];
	}

	int search(int left, int right, int node, int node_left, int node_right) {
		if (right < node_left || left > node_right) {
			return 0;
		}
		if (left <= node_left && right >= node_right) {
			return tree[node];
		}
		int mid = node_left + (node_right - node_left) / 2;

		int left_v = search(left, right, node * 2, node_left, mid);
		int right_v = search(left, right, node * 2 + 1, mid + 1, node_left);
		
		return merge(left_v, right_v);
	}

	int update(int idx, int newValue, int node, int node_left, int node_right) {
		if (idx < node_left || idx >node_right) {
			return tree[node];
		}
		if (node_left == node_right) {
			tree[node] = newValue;
			return tree[node];
		}
		int mid = node_left + (node_right - node_left) / 2;
		int left_v = update(idx, newValue, node * 2, node_left, mid);
		int right_v = update(idx, newValue, node * 2 + 1, mid + 1, node_right);
		return merge(left_v, right_v);
	}
};

int main() {
	sTree t;
	t.build(10);

	cout << t.set(arr,1,0,9) << "\n";
	for (int i = 0; i <= 24; i++) {
		cout << t.tree[i] << "\n";
	}

	
}