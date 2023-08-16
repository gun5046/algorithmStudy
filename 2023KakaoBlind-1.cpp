#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <map>
#include <unordered_map>

using namespace std;



class Date {
public:
    int year;
    int month;
    int day;

    Date() {

    }

    Date(string year, string month, string day) {
        this->year = stoi(year);
        this->month = stoi(month);
        this->day = stoi(day);
    }

    void update(int m) {

        this->day -= 1;
        if (this->day == 0) {
            this->month--;
            this->day = 28;
        }

        int quotient = m / 12;
        int remainder = m % 12;


        this->month += remainder;
        if (this->month > 12) {
            this->year++;
            this->month = this->month - 12;
        }

        this->year += quotient;
        return;
    }

};

Date tday;
vector<string> split(string str, char seperator) {
    stringstream s(str);

    string temp;
    vector<string> v;

    while (getline(s, temp, seperator)) {
        v.push_back(temp);
    }
    return v;
}

Date stringTodate(string str) {

    vector<string> v = split(str, '.');

    return Date(v[0], v[1], v[2]);

}

bool isValid(Date d) {
    if (d.year < tday.year) return false;
    else if (d.year > tday.year) return true;

    if (d.month < tday.month) return false;
    else if (d.month > tday.month) return true;

    if (d.day < tday.day) return false;

    return true;
}


map<string, int>m;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    Date tmp = stringTodate(today);
    tday = tmp;
    for (int i = 0; i < terms.size(); i++) {
        vector<string>v = split(terms[i], ' ');
        m.insert({ v[0],stoi(v[1]) });
    }

    for (int i = 1; i <= privacies.size(); i++) {
        vector<string>v1 = split(privacies[i - 1], ' ');
        Date d = stringTodate(v1[0]);
        d.update(m[v1[1]]);

        if (!isValid(d)) {
            answer.push_back(i);
        }
    }


    return answer;
}

int main() {
    string v1 = "2022.05.19";
    vector<string>v2;
    vector<string>v3;

    v2.push_back("A 6");
    v2.push_back("B 12");
    v2.push_back("C 3");
    v3.push_back("2021.05.02 A");
    v3.push_back("2021.07.01 B");
    v3.push_back("2022.02.19 C");
    v3.push_back("2022.02.20 C");
        
    solution(v1, v2, v3);
}