#include <string>
#include <sstream>
#include <vector>
#include <math.h>

using namespace std;

string changingNum(int n, int k);
vector<long long> split(string str);
bool isThisPrime(long long n);

int solution(int n, int k) {
    int answer = 0;
    string num = changingNum(n, k);

    vector<long long>num_list = split(num);

    for (int i = 0; i < num_list.size(); i++) {
        if (isThisPrime(num_list[i])) answer++;
    }

    return answer;
}

string changingNum(int n, int k) {
    string str_num = "";
    vector<int> num;
    while (n != 0) {
        int a = n % k;
        num.push_back(a);
        n = n / k;
    }
    for (int i = num.size() - 1; i >= 0; i--) {
        str_num += num[i] + '0';
    }
    return str_num;
}

vector<long long> split(string str) {
    istringstream iss(str);
    string temp;
    vector<string>res;
    vector<long long> result;
    while (getline(iss, temp, '0')) {
        res.push_back(temp);
    }

    for (string s : res) {
        long long num = 0;
        for (int i = 0; i < s.length(); i++) {

            num += (s[i] - '0') * (pow(10, s.length() - i - 1));
        }
        result.push_back(num);
    }
    return result;
}

bool isThisPrime(long long n) {
    int rootNum = (int)sqrt(n);

    if (n == 1 || n == 0) return 0;

    for (int i = 2; i <= rootNum; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}