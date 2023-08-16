#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <iostream>
#include <utility>
using namespace std;

pair<int, string> changeBinary(long long num) {
    bitset<64>binary(num);
    string binaryString = binary.to_string();
    int start;
    for (start = 0; start < binaryString.length(); start++) {
        if (binaryString[start] == '1') break;
    }

    string str = binaryString.substr(start, binaryString.length() - start);
    int i = 1;
    while (pow(2, i) - 1 < str.length()) {
        i++;
    }

    string plus(pow(2, i) - 1 - str.length(), '0');

    return { i,'0' + plus + str };
}

bool isValid(string str, int n, int depth) {
    if (depth == 1) {
        return true;
    }
    if (n - pow(2, depth - 2) > 0) {
        if (str[n - pow(2, depth - 2)] == '1') {
            if (str[n] == '0')
                return false;
        }
    }
    if (n + pow(2, depth - 2) <= str.length()) {
        if (str[n + pow(2, depth - 2)] == '1') {
            if (str[n] == '0')
                return false;
        }
    }

    return isValid(str, n - pow(2, depth - 2), depth - 1) && isValid(str, n + pow(2, depth - 2), depth - 1);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;

    for (int i = 0; i < numbers.size(); i++) {
        pair<int, string> binary = changeBinary(numbers[i]);

        if (isValid(binary.second, binary.second.length() / 2, binary.first)) {
            answer.push_back(1);
        }
        else {
            answer.push_back(0);
        }

    }

    return answer;
}