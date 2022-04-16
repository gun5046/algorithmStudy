#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

stack<int> st;
queue<int>q[30];
int cnt;

void move(int c) {
    if (q[c].empty()) {
        return;
    }
    int num = q[c].front();
    q[c].pop();

    if (st.empty()) {
        st.push(num);
    }
    else {
        int a = st.top();
        cout << a << num << "\n";
        if (a == num) {
            cnt++;
            st.pop();
        }
        else {
            st.push(num);
        }
    }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int n = board.size();
    cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) {
                continue;
            }
            q[j].push(board[i][j]);
        }
    }

    for (int i = 0; i < moves.size(); i++) {
        move(moves[i] - 1);
    }
    answer = cnt;
    return answer;
}

int main() {
    vector<int>moves;
    vector<vector<int>>board;
    int l;
    vector<int> v;
    for (int i = 0; i < 5; i++) {
        board.push_back(v);
        for (int j = 0; j < 5; j++) {
            cin >> l;
            board[i].push_back(l);
        }
    }

    for (int i = 0; i < 8; i++) {
        cin >> l;
        moves.push_back(l);
    }

    cout << solution(board, moves);
}