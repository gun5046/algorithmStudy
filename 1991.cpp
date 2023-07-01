#include <iostream>
#include <vector>

using namespace std;
int n;

class Node {
public:
	int left = 0;
	int right = 0;
	bool lchild = true;
	bool rchild = true;

	Node() {

	}
	void setNodeLeft(int l) {
		left = l;
	}
	void setNodeRight(int r) {
		right = r;
	}
	void setlChild(bool f) {
		lchild = f;
	}
	void setrChild(bool f) {
		rchild = f;
	}
};
Node node[26];
void preorder(int idx) {
	cout << (char)(idx + 'A');
	if (node[idx].lchild) {
		preorder(node[idx].left);
	}
	if (node[idx].rchild) {
		preorder(node[idx].right);
	}

}
void inorder(int idx) {
	if (node[idx].lchild) {
		inorder(node[idx].left);
	}
	cout << (char)(idx + 'A');
	if (node[idx].rchild) {
		inorder(node[idx].right);
	}
}
void postorder(int idx) {
	if (node[idx].lchild) {
		postorder(node[idx].left);
	}
	if (node[idx].rchild) {
		postorder(node[idx].right);
	}
	cout << (char)(idx + 'A');
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c1;
		char c2;
		char c3;
		cin >> c1 >> c2 >> c3;

		if (c2 == '.') {
			node[c1 - 'A'].setlChild(0);
		}
		else {
			node[c1 - 'A'].setNodeLeft(c2 - 'A');
		}
		if (c3 == '.') {
			node[c1 - 'A'].setrChild(0);
		}
		else {
			node[c1 - 'A'].setNodeRight(c3 - 'A');
		}
	}
	preorder(0);
	cout << "\n";
	inorder(0);
	cout << "\n";
	postorder(0);
}