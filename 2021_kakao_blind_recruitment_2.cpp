#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
unordered_map<string, int> m[10];



void course_map(string s, string str, int c, int k, int start) {
    if (k == 0) {
        sort(str.begin(), str.end());
        if (m[c].find(str) != m[c].end()) {
            m[c].find(str)->second += 1;
        }
        m[c].insert({ str,1 });
        return;
    }
    for (int i = start; i <= s.size() - k; i++) {
        string str1 = str + s[i];
        course_map(s, str1, c, k - 1, i + 1);
    }
}

vector<string> findMaximum(int c) {
    int maximum = 0;
    vector<string>max_str;
    unordered_map<string, int>::iterator iter;
    for (auto iter = m[c].begin(); iter != m[c].end(); iter++) {
        if (iter->second < 2) continue;
        if (iter->second > maximum) {
            maximum = iter->second;
            max_str.clear();
            max_str.push_back(iter->first);
        }
        else if (iter -> second == maximum) {
            max_str.push_back(iter->first);
        }
    }
    return max_str;
}
vector<string> solution(vector<string> orders, vector<int> course) {
    vector<string> answer;
    priority_queue<string>pq;

    for (int i = 0; i < course.size(); i++) {
        for (int j = 0; j < orders.size(); j++) {
            if (orders[j].size() >= course[i]) {
                course_map(orders[j], "", course[i], course[i], 0);
            }
        }
    }

    for (int i = 0; i < course.size(); i++) {
        vector<string>v = findMaximum(course[i]);
        for (int j = 0; j < v.size(); j++) {
            cout << v[j];
            pq.push(v[j]);
        }
    }
    while (!pq.empty()) {
        answer.push_back(pq.top());
        pq.pop();
    }
    return answer;
}

int main() {
    vector<string>orders;
    vector<int>course;

    orders.push_back("ABCFG");
    orders.push_back("AC");
    orders.push_back("CDE");
    orders.push_back("ACDE");
    orders.push_back("BCFG");
    orders.push_back("ACDEH");

    course.push_back(2);
    course.push_back(3);
    course.push_back(4);

    solution(orders, course);
}