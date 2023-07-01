#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;


int res[1000];
priority_queue<int>pq;

void order(vector<int>p) {
    int i = 0;
    while (!pq.empty()) {
        int v = -pq.top();
        pq.pop();
        if (p[i] == v) {
            i++;
            continue;
        }
        for (int j = i; j < p.size(); j++) {
            if (p[j] == v) {
                p[j] = p[i];
                p[i] = v;
                res[i]++;
                res[j]++;
                break;
            }
        }
        i++;
    }
}
vector<int>answer;
vector<int> solution(vector<int> p) {
    
    for (int i = 0; i < p.size(); i++) {
        pq.push(-p[i]);
    }
    order(p);

    for (int i = 0; i < p.size(); i++) {
        answer.push_back(res[i]);
    }
    return answer;
}

int main() {
    vector<int>p;
    p.push_back(2);

    p.push_back(5);


    p.push_back(3);


    p.push_back(1);


    p.push_back(4);


    solution(p);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
}