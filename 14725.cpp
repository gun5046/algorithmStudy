#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <math.h>
#include <list>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <sstream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
vector<string>v[1000];

class Trie {
public :
	/*Trie* child[26];*/
	map<string,Trie> child;
	map<string, Trie>::iterator iter;
	bool finish=false;
	
	void insert(vector<string> str,int idx) {
		if (str.size()==idx) {
			this->finish = true;
			return;
		}
		
		string s = str[idx];
		if (child.find(s) == child.end()) {
			child[s]=Trie();
		}
		child[s].insert(str,idx+1);
	}
	bool find(vector<string>str, int idx) {
		if (idx == str.size()) {
			if (this->finish) {	
				return true;
			}
			return false;
		}
		string s = str[idx];
		if (child.find(s) == child.end()) {
			return false;
		}
		child[s].find(str,idx+1);
	}

	void showAll(int depth) {
		if (!child.empty()) {
			for (iter = child.begin(); iter != child.end(); iter++) {
				for (int i = 0; i < depth; i++) {
					cout << "--";
				}
				cout << iter->first << "\n";
				iter->second.showAll(depth+1);
			}
		}
	}
};

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		string str;
		cin.ignore();
		getline(cin, str);
		istringstream ss(str);
		string temp;
		while (getline(ss, temp, ' ')) {
			v[i].push_back(temp);
		}
	}
	Trie trie = Trie();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			trie.insert(v[i],0);
		}
	}
	trie.showAll(0);
	
}