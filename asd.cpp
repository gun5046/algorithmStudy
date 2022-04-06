#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <math.h>
#include <iostream>

using namespace std;

priority_queue<string, vector<string>, greater<string>>read;
priority_queue<string, vector<string>, greater<string>>write;

vector<string> solution(vector<string>arr, vector<string>processes);
void stringDivision(vector<string> processes);
vector<string> asdstart(vector<string>arr);
int main() {
    vector<string>arr;
    vector<string>processes;

    arr.push_back("1");
    arr.push_back("1");
    arr.push_back("1");
    arr.push_back("1");
    arr.push_back("1");
    arr.push_back("1");
    arr.push_back("1");
    
    processes.push_back("write 1 12 1 5 8");
    processes.push_back("read 2 3 0 2");
    processes.push_back("read 5 5 1 2");
    processes.push_back("write 4 3 3 5 2");
    processes.push_back("read 7 5 2 5");
    processes.push_back("write 13 4 0 1 3");
    processes.push_back("write 19 3 3 5 5");
    processes.push_back("read 30 4 0 6");
    processes.push_back("read 32 3 1 5");
    vector <string> answer = solution(arr, processes);
    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << "\n";
    }
}

vector<string> solution(vector<string> arr, vector<string> processes) {

    stringDivision(processes);
    
    vector<string> answer= asdstart(arr);
    return answer;
}

void stringDivision(vector<string> processes) {
    for (int i = 0; i < processes.size(); i++) {
        if (processes[i].substr(0, 4) == "read") {
            read.push(processes[i].substr(5));
        }
        else {
            write.push(processes[i].substr(6));
        }
    }
}
vector<string> asdstart(vector<string> arr) {
    int time = 0;
    bool read_used = false;
    bool write_used = false;
    bool write_waiting = false;
    int cnt = 1;
    vector<string>res;
    while (1) {
        time++;
        cnt--;
        string read_str;
        string write_str;

        if (read.empty() && write.empty()) {
            break;
        }
        if (read.empty()) {
            read_str = "9999999 99999 99999 99999";
        }
        else {
            read_str = read.top();
        }
        if (write.empty()) {
            write_str = "9999999 99999 99999 99999 9";
        }
        else {
            write_str = write.top();
        }
        istringstream read_ss(read_str);
        istringstream write_ss(write_str);
        string buffer;
        vector<string>read_v;
        vector<string>write_v;
        read_v.clear();
        write_v.clear();

        while (getline(read_ss, buffer, ' ')) {
            read_v.push_back(buffer);
        }

        while (getline(write_ss, buffer, ' ')) {
            write_v.push_back(buffer);
        }
        int read_start_time = 0;
        int write_start_time = 0;
        int reading_time = 0;
        int writing_time = 0;
        int read_start_idx = 0;
        int read_end_idx = 0;
        int write_start_idx = 0;
        int write_end_idx = 0;
        for (int i = read_v[0].length() - 1; i >= 0; i--) {
            read_start_time += (read_v[0][i] - '0') * pow(10, i);
        }
        for (int i = write_v[0].length() - 1; i >= 0; i--) {
            write_start_time += (write_v[0][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            reading_time += (read_v[1][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            writing_time += (write_v[1][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            read_start_idx += (read_v[2][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            write_start_idx += (write_v[2][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            write_end_idx += (write_v[3][i] - '0') * pow(10, i);
        }
        for (int i = read_v[1].length() - 1; i >= 0; i--) {
            read_end_idx += (read_v[3][i] - '0') * pow(10, i);
        }
        int write_letter = write_v[4][0] - '0';


        if (cnt == 0) {
            read_used = false;
            write_used = false;
        }

        if (write_start_time <= time) {
            if (cnt == 0) {
                write.pop();
                for (int i = write_start_idx; i <= write_end_idx; i++) {
                    arr[i] = write_letter + '0';
                }
                cnt = writing_time;
                write_waiting = false;
                write_used = true;
            }
            else {
                write_waiting = true;
            }
        }
        if (read_start_time <= time) {
            if (!write_used) {
                if (!write_waiting) {
                    read.pop();
                    if (reading_time >= cnt) {
                        cnt = reading_time;
                    }
                    read_used = true;
                    string s = "";
                    for (int i = read_start_idx; i <= read_end_idx; i++) {
                        s += arr[i];
                    }
                    res.push_back(s);
                }
            }
        }
    }
    int c;
    

    return res;
}