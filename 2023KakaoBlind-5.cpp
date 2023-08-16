#include <string>
#include <vector>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
using namespace std;

struct Cell {
    string value = "";
    pair<int, int> parent;

    void init(int r, int c) {
        this->parent = { r,c };
    }
};

class Cells {
public:
    Cell node[51][51];

    void init() {
        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                node[i][j].init(i, j);
            }
        }
    }

    void update(int r, int c, string v) {
        pair<int, int> p = findParent(r, c);
        node[p.first][p.second].value = v;

    }

    void update(string v1, string v2) {
        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                pair<int, int> p = findParent(i, j);
                if (node[p.first][p.second].value == v1) {
                    node[p.first][p.second].value = v2;
                }
            }
        }
    }

    void merge(int r1, int c1, int r2, int c2) {
        if (r1 == r2 && c1 == c2) return;

        pair<int, int> x = findParent(r1, c1);
        pair<int, int> y = findParent(r2, c2);


        if (node[x.first][x.second].value.length() == 0 && node[y.first][y.second].value.length() != 0) {
            node[x.first][x.second].value = node[y.first][y.second].value;
        }

        node[y.first][y.second].parent = x;
        node[r2][c2].parent = x;
        // node[y.first][y.second].value = "";
        // node[r2][c2].value="";
    }

    pair<int, int> findParent(int r, int c) {
        if (node[r][c].parent == make_pair(r, c)) {
            return { r,c };
        }
        else {
            return node[r][c].parent = findParent(node[r][c].parent.first, node[r][c].parent.second);
        }
    }
    void unmerge(int r, int c) {
        pair<int, int>p = findParent(r, c);
        string v = node[p.first][p.second].value;
        vector<pair<int, int>>temp;
        for (int i = 1; i < 51; i++) {
            for (int j = 1; j < 51; j++) {
                if (findParent(i, j) == make_pair(p.first, p.second)) {
                    temp.push_back({ i,j });
                    if (i == r && j == c) {
                        node[i][j].value = v;
                    }
                    else {
                        node[i][j].value = "";
                    }
                }

            }
        }
        for (int i = 0; i < temp.size(); i++) {
            int x = temp[i].first;
            int y = temp[i].second;
            node[x][y].parent = { x,y };
        }


    }

    string print(int r, int c) {
        pair<int, int> p = findParent(r, c);


        return node[p.first][p.second].value;
    }

};

vector<string> split(string str) {

    stringstream ss(str);
    string temp;
    vector<string>v;
    while (getline(ss, temp, ' ')) {
        v.push_back(temp);
    }

    return v;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    Cells cells;
    cells.init();

    for (int i = 0; i < commands.size(); i++) {
        vector<string>cmd = split(commands[i]);
        if (cmd[0] == "UPDATE") {
            if (cmd.size() == 4) {
                cells.update(stoi(cmd[1]), stoi(cmd[2]), cmd[3]);
            }
            else {
                cells.update(cmd[1], cmd[2]);
            }
        }
        else if (cmd[0] == "MERGE") {
            cells.merge(stoi(cmd[1]), stoi(cmd[2]), stoi(cmd[3]), stoi(cmd[4]));
        }
        else if (cmd[0] == "UNMERGE") {
            cells.unmerge(stoi(cmd[1]), stoi(cmd[2]));
        }
        else {
            string output = cells.print(stoi(cmd[1]), stoi(cmd[2]));
            if (output.length() == 0) {
                answer.push_back("EMPTY");
            }
            else {
                answer.push_back(output);
            }
        }
    }

    return answer;
}