#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>

using namespace std;

vector<int> dir[17];
bool visited[17][17];
bool visitNode[17];
int node[17];

int solution(vector<int> info, vector<vector<int>> edges);
void initialization(int n, vector<vector<int>> edges);
void findDir(int n, vector<int> info);


int main() {
    int n,a,b;
    vector<int>info;
    
    vector<vector<int>> edges;
    for (int i = 0; i < 12; i++) {
        cin >> n;
        info.push_back(n);
    }
    for (int i = 0; i < 11; i++) {
        cin >> a >> b;
        vector<int>v;
        v.push_back(a);
        v.push_back(b);
        edges.push_back(v);
    }
    solution(info, edges);
}

int solution(vector<int> info, vector<vector<int>> edges) {
    int answer = 0;
    int n = info.size();
    initialization(n, edges);

    findDir(n, info);

    return answer;
}

void initialization(int n, vector<vector<int>> edges) {
    for (int i = 0; i < n; i++) {
        node[i] = -1;
        visitNode[i] = false;
        for (int j = 0; j < n; j++) {
            visited[i][j] = false;
        }
    }

    for (int i = 0; i < edges.size(); i++) {
        dir[edges[i][0]].push_back(edges[i][1]);
        dir[edges[i][1]].push_back(edges[i][0]);
    }

}

void findDir(int n, vector<int> info) {
    queue<pair<int, int>>q;
    int to; int c;
    for (int i = 0; i < dir[0].size(); i++) {
        to = dir[0][i];
        if (info[to] == 1) {
            c = 0;
        }
        else {
            c = 2;
        }
        visited[0][to] = true;
        visitNode[0] = true;
        q.push({ dir[0][i], c });
    }

    while (!q.empty()) {

        to = q.front().first;
        c = q.front().second;
        visitNode[to] = true;
        q.pop();
        for (int i = 0; i < dir[to].size(); i++) {
            int nstart = to;
            int nto = dir[to][i];

            

            if (visited[nstart][nto]) {
                if (c <= node[nto]) continue;
            }
            else {
                if (visitNode[nto]) {
                    if (info[nto] == 1) {
                        c++;
                    }
                    else {
                        c--;
                    }
                }
                else {
                    if (info[nto] == 1) {
                        c--;
                    }
                    else {
                        c++;
                    }
                }
                if (c < 0) continue;
                visited[nstart][nto] = true;
                           
            }
            q.push({ nto, c });
            node[nto] = c;
        }
    }
}

/*0 0 1 1 1 0 1 0 1 0 1 1
0 1
1 2
1 4
0 8
8 7
9 10
9 11
4 3
6 5
4 6
8 9
*/