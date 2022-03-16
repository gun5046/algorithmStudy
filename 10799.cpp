#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<int> st;
int main() {
	
	int total=0;
	int stick;
	char last;
	string str;
	cin >> str;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push(str[i]);
			stick=st.size() - 1;
			last = '(';
		}
		else {
			
			if (last == '(') {
				st.pop();
				total += stick;
			}
			else {
				total += 1;
				st.pop();
			}
			last = ')';
		}
	}
	
	cout << total;
}