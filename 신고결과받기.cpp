#include <string>
#include <vector>
#include <set>
#include <cstring>
#include <map>

using namespace std;

vector<int>solution(vector<string> id_list, vector<string> report, int k) {
    map<string, set<string>> m;
    map<string, int>m2;
    vector<int>answer;
    for (int i = 0; i < id_list.size(); i++) {
        set<string>s;
        m.insert({ id_list[i],s });
        m2.insert({ id_list[i], 0 });
    }

    for (int i = 0; i < report.size(); i++) {
        int blank = report[i].find(" ");
        string str1 = report[i].substr(0, blank);
        string str2 = report[i].substr(blank + 1);

        m[str2].insert(str1);
    }

    map<string, set<string>> ::iterator iter = m.begin();
    for (iter; iter != m.end(); iter++) {
        if (iter->second.size() >= k) {
            for (string s : iter->second) {
                m2[s] += 1;
            }
        }
    }
    for (int i = 0; i < id_list.size(); i++) {
        answer.push_back(m2[id_list[i]]);
    }
    return answer;
}