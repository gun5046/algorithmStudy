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
// U X 업, D X 다운, C 딜리트, Z 복구 , n 행개수, k 첫선택위치, cmd 명령

class Node {
public:
    int up_i;
    int down_i;
    bool status;

    Node() {
        up_i = 0;
        down_i = 0;
        status = true;
    }
};

Node* node = new Node[1000000];
int idx;
int a;
int front;
int back;
stack<pair<int, Node>>s;
void move(int c) {
    if (c < 0) {
        c = -c;
        for (int i = 0; i < c; i++) {
            idx = node[idx].up_i;
        }
    }
    else {
        for (int i = 0; i < c; i++) {
            idx = node[idx].down_i;
        }
    }
}

void deleteIdx() {

    node[idx].status = false;
    s.push({ idx,node[idx] });
    int up_idx = node[idx].up_i;
    int down_idx = node[idx].down_i;

    if (idx == front) {
        node[up_idx].up_i = node[up_idx].down_i;
        front = up_idx;
    }
    else if(idx == node[front].down_i){
        node[up_idx].down_i = node[idx].down_i;
        node[up_idx].up_i = node[idx].down_i;
        node[down_idx].up_i = node[idx].up_i;
    }
    else if (idx == back) {
        node[down_idx].down_i = node[down_idx].up_i;
        back = down_idx;
    }
    else if(idx == node[back].up_i){
        node[down_idx].down_i = node[idx].up_i;
        node[down_idx].up_i = node[idx].up_i;
        node[up_idx].down_i = node[idx].down_i;
    }
    else {
        node[up_idx].down_i = down_idx;
        node[down_idx].up_i = up_idx;
    }
    idx = down_idx;
}

void restore() {
    int res_i = s.top().first;
    Node nd = s.top().second;
    s.pop();
    int up_idx = nd.up_i;
    int down_idx = nd.down_i;
    node[res_i].status = true;
    if (res_i < front) {
        node[up_idx].up_i = res_i;
        front = res_i;
    }
    else if (up_idx == front) {
        node[up_idx].down_i = res_i;
        node[up_idx].up_i = res_i;
        node[down_idx].up_i = res_i;
    }
    else if (res_i > back) {
        node[up_idx].down_i = res_i;
        back = res_i;
    }
    else if (down_idx == back) {
        node[down_idx].down_i = res_i;
        node[down_idx].up_i = res_i;
        node[up_idx].down_i = res_i;
    }
    else {
        node[up_idx].down_i = res_i;
        node[down_idx].up_i = res_i;
    }
}
void table(vector<string> cmd) {
    for (int i = 0; i < cmd.size(); i++) {
        switch (cmd[i][0]) {
        case 'U':
            move(-(cmd[i][2] - '0'));
            break;
        case 'D':
            move(cmd[i][2] - '0');
            break;
        case 'C':
            deleteIdx();
            break;
        case 'Z':
            restore();
            break;
        }
        cout << idx;
        for (int j = 0; j < a; j++) {
            
            if (node[j].status) {
                cout << "O";
            }
            else {
                cout << "X";
            }
        }
        cout << "\n";
        cout << front<<" " << back << "\n";
    }
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    a = n;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            node[i].up_i = 1;
            node[i].down_i = 1;
        }
        else if (i == n - 1) {
            node[i].up_i = n - 2;
            node[i].down_i = n - 2;
        }
        else {
            node[i].up_i = i - 1;
            node[i].down_i = i + 1;
        }
    }
    idx = k;
    front = 0;
    back = n - 1;
    table(cmd);
    for (int i = 0; i < n; i++) {
        if (node[i].status) {
            answer += 'O';
        }
        else {
            answer += 'X';
        }
    }
    cout << answer;
    return answer;
}

int main() {
    vector<string> v;
    v.push_back("D 1");
    v.push_back("C");
    v.push_back("C");
    v.push_back("C");
    v.push_back("C");
    v.push_back("C");
    v.push_back("U 1");
    v.push_back("C");
    v.push_back("Z");
    v.push_back("U 2");
    v.push_back("C");


    solution(8,0,v);
}