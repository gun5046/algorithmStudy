#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
void zero(int num);


int main() {
	
	int k;
	int num, sum=0;
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> num;
		zero(num);
	}
	
	int c = st.size();
	for (int i = 0; i < c; i++) {
		sum += st.top();
		st.pop();
	}

	cout << sum;
}

void zero(int num) {
	if (num == 0) {
		if (st.empty()) {

		}
		else {
			st.pop();
		}
	}
	else {
		st.push(num);
	}
}

