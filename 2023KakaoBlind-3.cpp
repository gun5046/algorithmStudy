#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

vector<int>c_emoticons;
vector<vector<int>>c_users;
priority_queue<pair<int, int>>pq;
vector<int>sales(7);
void getPrice() {
    int totalPrice = 0;
    int totalRegist = 0;
    for (int i = 0; i < c_users.size(); i++) {
        int limitRate = c_users[i][0];
        int limitPrice = c_users[i][1];
        int price = 0;
        for (int j = 0; j < sales.size(); j++) {
            if (sales[j] < limitRate) continue;
            price += (c_emoticons[j] / 100) * (100 - sales[j]);
        }
        if (price >= limitPrice) {
            totalRegist++;
        }
        else {
            totalPrice += price;
        }
    }

    pq.push({ totalRegist,totalPrice });
    return;
}

void getCombination(int idx, int end) {
    if (idx == end) {
        getPrice();
        return;
    }
    else {

        for (int i = 10; i <= 40; i += 10) {
            sales[idx] = i;
            getCombination(idx + 1, end);
        }
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    c_users = users;
    c_emoticons = emoticons;

    int len = emoticons.size();

    getCombination(0, len);
    if (!pq.empty()) {
        int resultA = pq.top().first;
        int resultB = pq.top().second;

        answer.push_back(resultA);
        answer.push_back(resultB);
    }
    return answer;
}