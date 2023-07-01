#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cstring>

using namespace std;
int n, m;
long long t;
int arrA[1000], arrB[1000];
long long cnt = 0;

vector<int>v1;
vector<int>v2;
map<long long , long long>map1;
map<long long , long long >map2;

int find(long long  t) {
	if (map2.find(t) == map2.end()) {
		return 0;
	}
	else {
		return map2[t];
	}
}

void arrSum() {
	
	map<long long , long long > ::iterator iter1=map1.begin();
	
	int back = 0;
	int front = map2.size()-1;
	int mid = (front+back)/2;
	for (iter1; iter1 != map1.end(); iter1++) {
		int nt = t - iter1->first;
		cnt += find(nt)*(iter1->second);
	}
	return;
}

int main() {
	cin >> t >> n;

	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arrB[i];
	}
	int sum=0;
	for (int i = 0; i < n; i++) {
		sum = 0;
		sum += arrA[i];
		if (map1.find(sum)==map1.end()) {
			map1.insert({ sum ,1 });
		}
		else {
			map1[sum]++;
		}
		
		for (int j = i + 1; j < n; j++) {
			sum += arrA[j];
			if (map1.find(sum) == map1.end()) {
				map1.insert({ sum ,1 });
			}
			else {
				map1[sum]++;
			}
		}
	}
	sum = 0;
	for (int i = 0; i < m; i++) {
		sum = 0;
		sum += arrB[i];
		if (map2.find(sum) == map2.end()) {
			map2.insert({ sum ,1 });
		}
		else {
			map2[sum]++;
		}
		for (int j = i + 1; j < m; j++) {
			sum += arrB[j];
			if (map2.find(sum) == map2.end()) {
				map2.insert({ sum ,1 });
			}
			else {
				map2[sum]++;
			}
		}
	}//1000000

	arrSum();

	cout << cnt;
}

//¸Þ¸ð¸® 6400000000
/*int find(int t, int mid, int front, int back) {
	if (front == back) return 0;
	if (v2[mid] == t) {
		int m = mid;
		int b=mid; int f=mid;
		while (--m >=0 && v2[m] == t) {
			b = m;
		}
		while (++mid <= v2.size()-1 && v2[mid] == t) {
			f = mid;
		}
		return f - b+1;
	}
	else if (v2[mid] > t) {
		find(t, (back + mid) / 2, mid, back);
	}
	else {
		find(t, (mid + front) / 2, front, mid);
	}
}

void arrSum() {
	int back = 0;
	int front = v2.size() - 1;
	int mid = v2.size() / 2;
	for (int i = 0; i < v1.size(); i++) {
		int nt = t - v1[i];
		cnt += find(nt, mid, front, back);
	}
	return;
}

int main() {
	cin >> t >> n;

	for (int i = 0; i < n; i++) {
		cin >> arrA[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> arrB[i];
	}
	int sum;
	for (int i = 0; i < n; i++) {
		sum = 0;
		sum += arrA[i];
		v1.push_back(sum);
		for (int j = i+1; j < n; j++) {
			sum += arrA[j];
			v1.push_back(sum);
		}
	}
	
	for (int i = 0; i < m; i++) {
		sum = 0;
		sum += arrB[i];
		v2.push_back(sum);
		for (int j = i+1; j < m; j++) {
			sum += arrB[j];
			v2.push_back(sum);
		}
	}//1000000
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end()); //10000000
	
	arrSum();

	cout << cnt;
}*/