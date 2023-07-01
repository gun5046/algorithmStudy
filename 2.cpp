#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <set>
#include <sstream>
#include <cstring>
#include <string>
#include <stack>

using namespace std;
vector<pair<int, int>> v[50001];
unordered_set<int>g;
set<int>s;
vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    for (int i = 0; i < paths.size(); i++) {
        v[paths[i][0]].push_back({ paths[i][1],paths[i][2] });
    }

    for (int i = 0; i < gates.size(); i++) {
        g.insert(gates[i]);
    }
    for (int i = 0; i < summits.size(); i++) {
        s.insert(summits[i]);
    }
    priority_queue<pair<int, int>>pq;
    for (int i = 0; i < gates.size(); i++) {
        int start = gates[i];
        int intensity = 0;
        bool visited[50001];
        memset(visited, 0, sizeof(visited));
        queue<int>q;
        g.erase(start);
        q.push(start);
        bool findSummit = false;
        priority_queue<pair<int,int>>pq1;
        int sum=0;
        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (int i = 0; i < v[now].size(); i++) {
                int next = v[now][i].first;
                int time = v[now][i].second;
                if (visited[next]) continue;
                if (g.find(next) != g.end()) continue;
                if (intensity <= time) intensity = time;
                if (findSummit) continue;
                if (s.find(next) != s.end()) {
                    findSummit = true;
                    sum = next;
                }
                else {
                    visited[next] = true;
                    q.push(next);
                }
            }
            
        }
        pq1.push({ -intensity, sum});

        g.insert(start);
    }

    cout << -pq.top().first << pq.top().second;
    return answer;
}

int main() {
    solution(6, { {1,2,3},{2,3,5 },{2,4,2 },{2,5,4},{3,4,4},{4,5,3},{4,6,1},{5,6,1} }, { 1,3 }, { 5 });
}