#include <string>
#include <vector>
#include <queue>
#include <map>
#include <utility>
#define endTime (23*60)+59
using namespace std;


map<string, int> m;

void calcTime(vector<string> records);
vector<int> calcFee(vector<int> fees);

vector<int> solution(vector<int> fees, vector<string> records) {
    calcTime(records);

    return calcFee(fees);
}

void calcTime(vector<string> records) {
    map<string, int> enter;

    for (int i = 0; i < records.size(); i++) {
        int hour = (records[i][0] - '0') * 10 + (records[i][1] - '0');
        int minute = (records[i][3] - '0') * 10 + (records[i][4] - '0') + hour * 60;
        string num = records[i].substr(6, 4);

        if (enter.count(num) == 0) {
            enter.insert({ num,minute });
        }
        else {
            int usingTime = minute - (enter.find(num)->second);

            if (m.count(num) == 0) {
                m.insert({ num, usingTime });
            }
            else {
                m[num] += usingTime;
            }
            enter.erase(num);
        }
    }

    for (map<string, int>::iterator iter = enter.begin(); iter != enter.end(); iter++) {
        int t = endTime - (iter->second);
        if (m.count(iter->first) == 0) {
            m.insert({ iter->first, t });
        }
        else {
            m[iter->first] += t;
        }
    }
}

vector<int> calcFee(vector<int> fees) {
    int defTime = fees[0];
    int defFee = fees[1];
    int unitTime = fees[2];
    int unitFee = fees[3];
    vector<int>answer;
    for (map<string, int> ::iterator iter = m.begin(); iter != m.end(); iter++) {
        int totalFee = defFee;
        int time = iter->second;

        if (time >= defTime) {
            totalFee += ((time - defTime) / unitTime) * unitFee;
            if ((time - defTime) % unitTime != 0) {
                totalFee += unitFee;
            }
        }
        answer.push_back(totalFee);
    }
    return answer;
}