#include <iostream>
#include <utility>
#include <vector>
#include <regex>
#include <string>
#include <queue>
using namespace std;

int n;
int max = 0;
vector<int>v;
vector<char>exec;
priority_queue<int>pq;
queue<int>q;
void bracket1(int a, int v_c, int e_c, int calc);
void bracket2(int a, int b, int v_c, int e_c, int calc);
int Calc(int a, int b, char c) {
	int n1;
	switch (c) {
		
	case '-':
		n1 = a - b;
		break;
	case '+':
		n1 = a + b;
		break;
	case '*':
		n1 = a * b;
		break;
	}
	return n1;
}

void bracket1(int a,int v_c,int e_c, int calc) {

	int n1 = Calc(calc, a, exec[e_c]);

	if (exec.size() - e_c >= 3) {
		bracket2(v[v_c + 1], v[v_c + 2], v_c + 2, e_c + 1, n1);
	}
	if (exec.size() - e_c > 1) {
		bracket1(v[v_c + 1], v_c + 1, e_c + 1, n1);
	}
	if(e_c==exec.size()-1) {
		pq.push(n1);
		q.push(n1);
	}
}


void bracket2(int a, int b, int v_c, int e_c, int calc) {
	
	
	int n1 =Calc(a, b, exec[e_c + 1]);
	int n2 = Calc(calc, n1, exec[e_c]);


	if (exec.size() - e_c  > 3) {
		bracket2(v[v_c + 1], v[v_c + 2], v_c + 2, e_c + 2, n2);
	}
	if (exec.size() - e_c >= 3) {
		bracket1(v[v_c+1], v_c + 1, e_c + 2, n2);
	}
	if (e_c==exec.size()-2){
		pq.push(n2);
		q.push(n1);
	}
}

void split(string str) {
	int back = 0, i=0;
	while (i!=n) {
		if (str[i] == '*' || str[i] == '+' || str[i] == '-') {
			string s = str.substr(back, i - back);
			back = i+1;
			v.push_back(stoi(s));
			exec.push_back(str[i]);
		}
		i++;
	}
	string s = str.substr(back, str.size() - back);
	v.push_back(stoi(s));
	return;
}

int main() {
	cin >> n;
	string str;
	cin >> str;
	
	split(str);
	if (v.size() >= 2) {
		bracket2(v[1], v[2], 2, 0, v[0]);
	}
	if (exec.size() >= 1) {
		bracket1(v[1], 1, 0, v[0]);
	}
	if (!pq.empty()) {
		cout << pq.top();
	}
	else {
		cout << v[0];
	}
    return 0;
}
