#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <utility>
#include <cstring>
using namespace std;

int arr[10] = { 1,2,3,4,5 };
bool check[10];
vector<int>v;
int cnt = 0;

void subset2(int depth, int idx) { // �������� ������
	if (depth == 5) {
		vector<int>v1;
		vector<int>v2;

		for (int i = 0; i < 5; i++) {
			if (check[i]) {
				v1.push_back(i);
			}
			else {
				v2.push_back(i);
			}
		}
		cout << "v1 : ";
		for (int i = 0; i < v1.size(); i++) {
			cout << arr[v1[i]] << " ";
		}
		cout << "\n";
		cout << "v2 : ";
		for (int i = 0; i < v2.size(); i++) {
			cout << arr[v2[i]] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}

	subset2(depth + 1, idx + 1);
	check[idx] = true;
	subset2(depth + 1, idx + 1);
	check[idx] = false;
}

void combination2(int depth, int idx) { // �������� ������
	if (depth == 3) {
		vector<int>v1;
		vector<int>v2;
		for (int i = 0; i < 5; i++) {
			if (check[i]) {
				v1.push_back(i);
			}
			else {
				v2.push_back(i);
			}
		}
		cout << "v : ";
		for (int i = 0; i < v1.size(); i++) {
			cout << arr[v1[i]] <<" ";
		}
		cout << "\n";
		cout << "v2 : ";
		for (int i = 0; i < v2.size(); i++) {
			cout << arr[v2[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < 5;  i++) {
		check[i] = true;
		combination2(depth + 1, i + 1);
		check[i] = false;
	}

}

void subset(int idx, int depth) { // �κ�����
	if (depth == 5) {
		for (int i = 0; i < v.size(); i++) {
			cout << arr[v[i]] << " ";
		}
		cout << "\n";
		cnt++;
		return;
	}
	v.push_back(idx);
	subset(idx + 1, depth + 1);
	v. pop_back();
	subset(idx + 1, depth + 1);
}


void reputation_combination(int depth, int idx) { // ���� �ε����� �����Ͽ� Ž�� +combination (�ߺ� O, ���� X)
	
	if (depth == 3) {
		for (int i = 0; i < 3; i++) {
			cout << arr[v[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = idx; i < 5; i++) {
		v.push_back(i);
		reputation_combination(depth + 1, i);
		v.pop_back();
	}
}

void reputation_permutation(int depth) { // check�迭 �ʿ� X, 0���ͽ��� (�ߺ� O, ���� O)
	if (depth == 3) {
		for (int i = 0; i < 3; i++) {
			cout << arr[v[i]] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < 5; i++) {
		v.push_back(i);
		reputation_permutation(depth+1);
		v.pop_back();
	}
}

void combination(int depth, int idx) { // check �迭 �ʿ� X, idx���� ����(�ߺ� X, ���� X)
	if (depth == 3) {
		for (int i = 0; i < v.size(); i++) {
			cout << arr[v[i]] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i < 5; i++) {
		v.push_back(i);
		combination(depth + 1, i + 1);
		v.pop_back();
	}
}

void permutation(int depth) { // check �迭 �ʿ� O, 0���� ����(�ߺ� X, ���� O)
	if (depth == 3) {
		for (int i = 0; i < v.size(); i++) {
			cout << arr[v[i]] <<" ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (check[i]) continue;
		check[i] = true;
		v.push_back(i);
		permutation(depth + 1);
		v.pop_back();
		check[i] = false;
	}
}

int main() {
	memset(check, 0, sizeof(check));
	//permutation(0);
	//combination(0, 0);
	//reputation_permutation(0);
	//reputation_combination(0,0);
	//subset(0,0); cout << cnt;
	//combination2(0,0);
	subset2(0, 0); cout << cnt;
}