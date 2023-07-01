#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <cstring>
using namespace std;
vector<int>win[101];
vector<int>lose[101];

int wcnt[101] = { 0, };
int lcnt[101] = { 0, };

bool wvisited[101];
bool lvisited[101];

bool tempvisit[101];
void windfs(int idx, int c, stack<int>st) {
    int len = win[idx].size();
    if (len == 0) {
        stack<int>temp = st;
        int a = 0;
        while (!temp.empty()) {
            int nd = temp.top();
            temp.pop();
            tempvisit[nd] = true;
            wvisited[nd] = true;
            wcnt[nd] += a;
            a++;
        }
        return;
    }
    else {
        for (int i = 0; i < len; i++) {
            int next = win[idx][i];
            if (tempvisit[next]) continue;
            if (wvisited[next]) {
                stack<int>temp = st;
                int a = wcnt[next]+1;
                while (!temp.empty()) {
                    int nd = temp.top();
                    temp.pop();
                    tempvisit[nd] = true;
                    wvisited[nd] = true;
                    wcnt[nd] += a;
                    a++;
                }
                continue;
            }
            tempvisit[next] = true;
            st.push(next);
            windfs(next, c + 1, st);
            st.pop();
        }
    }
    return;
}

void losedfs(int idx, int c, stack<int>st) {
    int len = lose[idx].size();
    if (len == 0) {
        stack<int>temp = st;
        int a = 0;
        while (!temp.empty()) {
            int nd = temp.top();
            temp.pop();
            tempvisit[nd] = true;
            lvisited[nd] = true;
            lcnt[nd] += a;
            a++;
        }
        return;
    }
    else {
        for (int i = 0; i < len; i++) {
            int next = lose[idx][i];
            if (tempvisit[next]) continue;
            if (lvisited[next]) {
                stack<int>temp = st;
                int a = lcnt[next]+1;
                while (!temp.empty()) {
                    int nd = temp.top();
                    temp.pop();
                    lvisited[nd] = true;
                    tempvisit[nd] = true;
                    lcnt[nd] += a;
                    a++;
                }
                continue;
            }
            tempvisit[next] = true;
            st.push(next);
            losedfs(next, c + 1, st);
            st.pop();
        }
    }
    return;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;

    for (vector<int> v : results) {
        int winner = v[0];
        int loser = v[1];

        win[winner].push_back(loser);
        lose[loser].push_back(winner);
    }

    for (int i = 1; i <= n; i++) {
        stack<int>st;
        st.push(i);
        memset(tempvisit, 0, sizeof(tempvisit));
        windfs(i, 0, st);
        memset(tempvisit, 0, sizeof(tempvisit));
        while (!st.empty()) {
            st.pop();
        }
        st.push(i);
        losedfs(i, 0, st);
        cout << wcnt[i] << " " << lcnt[i] << "\n";
    }

    for (int i = 1; i <= n; i++) {
        int a = wcnt[i];
        int b = lcnt[i];
        cout << a + b << " ";
        if (a + b == n - 1) answer++;
    }


    return answer;
}

int main() {
    vector<int>v;
    vector<vector<int>>m;
    v.push_back(4);
    v.push_back(3);
    m.push_back(v);
    v.clear();
    v.push_back(4);
    v.push_back(2);
    m.push_back(v);
    v.clear();
    v.push_back(3);
    v.push_back(2);
    m.push_back(v);
    v.clear();
    v.push_back(1);
    v.push_back(2);
    m.push_back(v);
    v.clear();
    v.push_back(2);
    v.push_back(5);
    m.push_back(v);
    v.clear();
    solution(5, m);
}