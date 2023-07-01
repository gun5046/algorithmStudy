#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
public :
	bool chk=true;
	int up;
	int down;
};

Node *node = new Node[1000000]();

int selected;

void movingUp(int x) {

	for(int i=0; i<x; i++)
		selected = node[selected].up;
}

void movingDown(int x) {
	
	for (int i = 0; i < x; i++)
		selected = node[selected].down;
}

void deleteColumn() {
	cout << "d" << endl;
	Node nodeTemp = node[selected];
	node[selected].chk = false;
	node[nodeTemp.up].down=nodeTemp.down;
	node[nodeTemp.down].up = nodeTemp.up;
	movingDown(1);
}

int main() {
	int n;
	int c;
	string str;
	vector<string> v;
	cin >> n >> selected>> c;
	for (int i = 0; i < n; i++) {
		node[i].up = i - 1;
		node[i].down = i + 1;
		if (i == 0) {
			node[i].up = i + 1;
		}
		if (i == n - 1) {
			node[i].down = i - 1;
		}
	}
	cin.ignore();
	for (int i = 0; i < c; i++) {
		getline(cin, str);
		v.push_back(str);
	}


	for (int i = 0; i < c; i++) {

		switch (v[i][0]) {
		case 'U' :
			
			movingUp(v[i][2]-'0');
			break;
		case 'D' :
			
			movingDown(v[i][2]-'0');
			break;
		case 'C' :
			deleteColumn();
			break;
		case 'Z' :
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << node[i].chk<<endl;
	}
	
}

