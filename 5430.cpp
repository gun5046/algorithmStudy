#include <iostream>
#include <vector>
#include <cstring>
#include <sstream>
#include <math.h>
#include <string>
using namespace std;

int t;
string func;
int n;
string str;
bool errflag = false;
bool dir = false;

int back;
int front;
void ac(vector<int> num);
vector<int> casting(vector<string> num);
void reverseN();
void deleteN();
string anwser;
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> func;
		cin >> n;
		cin >> str;
		errflag = false;
		dir = false;
		vector<string> num;
		string s="";
		for (int i = 1; i < str.size() - 1; i++) {
			s+=str[i];
		}
		istringstream ss(s);
		string temp;
		
		while (getline(ss, temp, ',')) {
			num.push_back(temp);
		}
		front = 0;
		back = n - 1;
		
		ac(casting(num));
	}
}
vector<int> casting(vector<string>num) {
	int t;
	vector<int>number;
	for (int i = 0; i < num.size(); i++) {
		t = 0;
		for (int j = 0; j < num[i].size(); j++) {
			t += (num[i][j]-'0') * pow(10,num[i].size()-j-1);
		}
		number.push_back(t);
	}
	return number;
}
void ac(vector<int> num) {
	for (int i = 0; i < func.size(); i++) {
		if (errflag) break;
		if (func[i] == 'R') {
			reverseN();
		}
		else {
			deleteN();
		}
	}
	
	if (errflag) {
		cout << "error" << "\n";
	}
	else {
		
		cout << "[";
		if (!dir) {
			for (int i = front; i <= back; i++) {
				cout << num[i];
				if (i != back) cout << ",";
			}
			
		}
		else {
			for (int i = back; i >= front; i--) {
				cout << num[i];
				if (i != front) cout << ",";
			}
		}
		cout << "]" << "\n";
	}
}
void reverseN() {
	dir = !dir;
}

void deleteN() {
	if (front > back) {
		errflag = true;
		return;
	}
	if (!dir) {	
		front++;
	}
	else {
		back--;
	}
}