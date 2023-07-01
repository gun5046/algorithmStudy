#include <iostream>
#include <vector>
#include <stack>

using namespace std;

stack<char>s;

string str;

bool solution() {
	for (int i = 0; i < str.size(); i++) {
		
		if (str[i] == '<' || str[i] == '{' || str[i] == '[' || str[i] == '(') {
			s.push(str[i]);
		}
		else {
			if (s.empty())
				return false;
			char c = s.top();
			s.pop();

			switch (str[i]) {
			
			case '>':
				if (c != '<')
					return false;
				break;
			case ')' :
				if (c != '(')
					return false;
				break;
			case '}' :
				if (c != '{')
					return false;
				break;
			case ']' :
				if (c != '[')
					return false; 
				break;
			}
		}
	}
	if (!s.empty()) {
		return false;
	}
	return true;
}
int main() {
	int n;
	for (int t =1; t <= 10; t++) {

		cin >> n;
		
		cin >> str;
		while (!s.empty()) {
			s.pop();
		}
		cout << "#" << t << " " << solution()<<"\n";
		
	}
}