#include <string>
#include <vector>
#include <iostream>

#define MAX 10000000

using namespace std;

bool arr[MAX];
int cnt = 0;
bool visit[7];
void makeString(string str, string num) {
    if (str.length() != 0) {
        int n = stoi(str);
        if (!arr[n]) cnt++;
    }
    for (int i = 0; i < num.size(); i++) {
        if (visit[i]) continue;
        visit[i] = true;
        makeString(str + num[i], num);
        visit[i] = false;
    }
    return;
}

int solution(string numbers) {
    for (int i = 2; i*i < MAX; i++) {
        if (arr[i]) continue;

        for (int j = i*i; j < MAX; j += i) {
            arr[j] = true;
        }
    }

    makeString("", numbers);

    return cnt;
}

int main() {
    solution("123");
}