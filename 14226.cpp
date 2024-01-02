#include<iostream>
#include<queue>
#define endl "\n"
#define MAX 2000

using namespace std;

int S;
bool Visit[MAX][MAX];

void Input() {
    cin >> S;
}

int BFS() {
    queue<pair<pair<int, int>, int>> Q;
    Q.push(make_pair(make_pair(1, 0), 0));
    Visit[1][0] = true; // 화면, 클립보드

    while (Q.empty() == 0) {
        int Dis = Q.front().first.first;
        int Clip = Q.front().first.second;
        int Time = Q.front().second;
        Q.pop();

        if (Dis == S)
            return Time;

        if (Dis > 0 && Dis < MAX) {
            if (Visit[Dis][Dis] == false) {
                Visit[Dis][Dis] = true;
                Q.push(make_pair(make_pair(Dis, Dis), Time + 1));
            }
            if (Visit[Dis - 1][Clip] == false) {
                Visit[Dis - 1][Clip] = true;
                Q.push(make_pair(make_pair(Dis - 1, Clip), Time + 1));
            }
        }
        if (Clip > 0 && Dis + Clip < MAX) {
            if (Visit[Dis + Clip][Clip] == false) {
                Visit[Dis + Clip][Clip] = true;
                Q.push(make_pair(make_pair(Dis + Clip, Clip), Time + 1));
            }
        }
    }
}

void Solution() {
    int R = BFS();
    cout << R << endl;
}

void Solve() {
    Input();
    Solution();
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("Input.txt", "r", stdin);
    Solve();
    return 0;
}
