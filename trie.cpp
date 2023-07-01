#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Trie {
public :
	Trie* ch[26];
	bool finish;
	Trie() {
		finish = false;
		for (int i = 0; i < 26; i++)
			ch[i] = NULL;
	}
	~Trie() {
		for(int i=0; i<26; i++)
			if (ch[i])
				delete ch[i];
	}
	void insert(const char* s) {
		if (!*s) {
			this->finish = true;
			cout << "\n";
			return;
		}
		int now = *s - 'A';
		cout << *s<<" ";
		if (!ch[now]) ch[now] = new Trie();
		ch[now]->insert(s + 1);
	}

	bool find(const char* s) {
		if (!*s) {
			if (finish) return true;
			return false;
		}
		int now = *s - 'A';
		if (!ch[now]) return false;
		return ch[now]->find(s + 1);
	}
};

int main() {
	Trie* root = new Trie();
	string a="AAB";
	string b="ABA";
	string c="AAA";
	string d="BAC";
	root->insert(a.c_str());
	root->insert(b.c_str());
	root->insert(c.c_str());
	root->insert(d.c_str());
	string tmp = "ABA";
	if (root->find(tmp.c_str())) cout << "Find";
	else cout << "NO";
	delete root;
}