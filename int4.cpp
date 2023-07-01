#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <unordered_map>
#include <unordered_set>
#include <math.h>
#include <sstream>
#include <cstring>
#include <string>
using namespace std;

priority_queue<int>pq;
vector<pair<int, int>>road[1000];
vector<pair<int, int>>back_road[1000];
bool trap[1000];

bool visited[1000][1000];
int findRoad(int n, int start, int end) {
    queue<pair<int, int>>q;
    for (int i = 0; i < road[start].size(); i++) {
        q.push(road[start][i]);
    }
    while (!q.empty()) {
        int now = q.front().first;
        int sum = q.front().second;
        q.pop();
        visited[start][now] = true;
        if (now == end) {
            pq.push(-sum);
            continue;
        }
        if (!trap[now]) {
            for (int i = 0; i < road[now].size(); i++) {
                int next = road[now][i].first;
                int time = road[now][i].second;
                if (visited[now][next]) continue;
                q.push({ next, sum + time });
            }
        }
        else {
            for (int i = 0; i < road[now].size(); i++) {
                trap[road[now][i].first] = !trap[road[now][i].first];
            }
            for (int i = 0; i < back_road[now].size(); i++) {
                int next = back_road[now][i].first;
                int time = back_road[now][i].second;
                if (visited[now][next]) continue;
                q.push({ next, sum + time });
            }
        }
        start = now;
    }
    int res = -pq.top();
    return res;
}
int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;

    for (int i = 0; i < roads.size(); i++) {
        int f = roads[i][0];
        int b = roads[i][1];
        int t = roads[i][2];

        road[f].push_back({ b,t });
        back_road[b].push_back({ f,t });
    }
    for (int i = 0; i < traps.size(); i++) {
        trap[traps[i]] = true;
    }
    answer = findRoad(n, start, end);
    return answer;
}

int main() {
    vector<int>v;
    vector<vector<int>>r;
    r.push_back({ 1,2,1 });
    r.push_back({ 3,2,1 });
    r.push_back({ 2,4,1 });
    v.push_back(2);
    v.push_back(3);

    solution(4,1,4,r,v);
}