#include <iostream>
#include <utility>
#include <algorithm>
#include <queue>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std; 

class Atom{
public :
	int x;
	int y;
	int d;
	int e;
	bool state = true;
	

	Atom(int x,int y, int d, int e) {
		this->x = x;
		this->y = y;
		this->d = d;
		this->e = e;
	}
};

vector<Atom> atom;
int n;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1,-1,0, 0 };
int energy = 0;


void move(int idx) {
	int dir = atom[idx].d;

	atom[idx].x += dx[dir];
	atom[idx].y += dy[dir];
}

void sol() {
	
	map<pair<int, int>, vector<int>>m;
	map<pair<int, int>, vector<int>> ::iterator iter = m.begin();
	for (int i = 0; i < n; i++) {
		if (!atom[i].state) continue;

		move(i);
		int nx = atom[i].x;
		int ny = atom[i].y;
		if (ny == 0 || ny == 0) {
			cout << nx << " " << ny;
		}
		cout << "\n";
		if (nx < -1000 || ny < -1000 || nx>1000 || ny >1000) {
			atom[i].state = false;
			continue;
		}

		if (m.find({ nx,ny }) == m.end()) {
			vector<int>v;
			v.push_back(i);
			m.insert({ {nx,ny},v });
		}
		else {
			m[{nx, ny}].push_back(i);
		}
	}

	for (iter; iter != m.end(); iter++) {
		if (iter->second.size() != 1) {
			for (int idx : iter->second) {
				atom[idx].state = false;
				energy+=atom[idx].e;
			}
		}
	}
	
	if (!m.empty()) {
		for (iter = m.begin(); iter != m.end(); iter++)
		{
			vector<int>().swap(iter->second);
		}
		m.clear();
		sol();
	}

	return;
}


int main() {
	int test=0;
	cin >> test;
	for (int t = 1; t <= test; t++) {
		
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			int a, b, c, d;
			energy = 0;
			cin >> a >> b >> c >> d;
			Atom at(a,b,c,d);

			atom.push_back(at);
		}

		sol();

		cout << "#" << t <<" "<<energy<<"\n";
	}
}