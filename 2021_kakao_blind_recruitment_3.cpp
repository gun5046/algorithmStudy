#include <string>
#include <vector>
#include <sstream>
#include <iostream>

using namespace std;

vector<string> split(string s) {
    string buffer;
    stringstream ss(s);
    vector<string>str;
    while (getline(ss, buffer, ' ')) {
        if (buffer == "and") continue;
        str.push_back(buffer);
    }
    return str;
}

int StringToInt(string s) {
    int i = 0;
    stringstream ssInt(s);
    ssInt >> i;
    return i;
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    vector<string> info_arr[50000];
    vector<string> query_arr;

    for (int i = 0; i < info.size(); i++) {
        vector<string> v = split(info[i]);
        for (string s : v) {
            info_arr[i].push_back(s);
        }
    }

    for (int i = 0; i < query.size(); i++) {
        int cnt = 0;
        if (i == 3) {
            cout << 1;
        }
        query_arr = split(query[i]);
        for (int j = 0; j < info.size(); j++) {
            bool flag = true;
            if (StringToInt(info_arr[j][4]) < StringToInt(query_arr[4])) continue;
            for (int k = 0; k < 4; k++) {
                if (query_arr[k] == "-") continue;
                if (info_arr[j][k][0] != query_arr[k][0]) {
                    flag = false;  break;
                }
            }
            if (flag) {
                cnt++;
            }
        }
        answer.push_back(cnt);
    }


    return answer;
}

int main() {
    vector<string> info = {
        "java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"
    };
    vector<string> query = { "java and backend and junior and pizza 100","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150" };
    solution(info, query);
}