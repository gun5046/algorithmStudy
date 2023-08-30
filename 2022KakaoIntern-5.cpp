#include <string>
#include <vector>
#include <deque>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

class Table {
public:
    deque<deque<int>> col; // 가로
    deque<deque<int>> row; // 세로

    Table(int r, int c) {
        col.resize(c);
        row.resize(2);
    }


    void rotate() {
        int temp = col[0].back();
        col[0].pop_back();

        row[1].push_front(temp);
        temp = row[1].back();
        row[1].pop_back();

        col[col.size() - 1].push_back(temp);
        temp = col[col.size() - 1].front();
        col[col.size() - 1].pop_front();

        row[0].push_back(temp);
        temp = row[0].front();
        row[0].pop_front();

        col[0].push_front(temp);
    }
    void shiftRow() {
        col.push_front(col[col.size() - 1]);
        col.pop_back();

        for (deque<int> d : row) {
            d.push_front(d[d.size() - 1]);
            d.pop_back();
        }
    }



};



vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer;
    Table tb = Table(rc[0].size(), rc.size());
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++) {
            if (j == 0) {
                tb.row[0].push_back(rc[i][j]);
            }
            else if (j == rc[i].size() - 1) {
                tb.row[1].push_back(rc[i][j]);
            }
            else {
                tb.col[i].push_back(rc[i][j]);
            }
        }
    }
    // for(int i=0; i<tb.col.size(); i++){
    //     for(int j=0; j<tb.col[i].size(); j++){
    //         cout << tb.col[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // for(int i=0; i<=1; i++){
    //     for(int j=0; j<tb.row[0].size(); j++){
    //         cout << tb.row[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    for (string cmd : operations) {
        if (cmd == "Rotate") {
            tb.rotate();
        }
        else {
            tb.shiftRow();
        }
        for (int i = 0; i < rc.size(); i++) {
            for (int j = 0; j < rc[i].size(); j++) {
                if (j == 0) {
                    rc[i][j] = tb.row[0][i];
                }
                else if (j == rc[i].size() - 1) {
                    rc[i][j] = tb.row[1][i];
                }
                else {
                    rc[i][j] = tb.col[i][j - 1];
                }
            }
        }
        for (int i = 0; i < rc.size(); i++) {
            for (int j = 0; j < rc[i].size(); j++) {
                cout << rc[i][j] << " ";
            }
            cout << "\n";
        }
    }
    for (int i = 0; i < rc.size(); i++) {
        for (int j = 0; j < rc[i].size(); j++) {
            if (j == 0) {
                rc[i][j] = tb.row[0][i];
            }
            else if (j == rc[i].size() - 1) {
                rc[i][j] = tb.row[1][i];
            }
            else {
                rc[i][j] = tb.col[i][j - 1];
            }
        }
    }
    answer = rc;

    return answer;
}