#include <string>
#include <vector>

using namespace std;

int mScore = 0;
int lScore = 0;
int lion[11];
vector<int>answer;
int big = 0;
int ans[11];
void sol(int n, int level, int c, vector<int>info) {

    if (n <= c) {
        int temp = 0;
        for (int i = level; i < 11; i++) {
            if (info[i] > 0) {
                temp += 10 - i;
            }
        }
        mScore += temp;
        if (lScore > mScore) {
            if (big < lScore - mScore) {
                big = lScore - mScore;
                for (int i = 0; i < 11; i++) {
                    ans[i] = lion[i];
                }
            }
            else if (big == lScore - mScore) {
                for (int i = 10; i >= 0; i--) {
                    if (ans[i] == lion[i]) {
                        continue;
                    }
                    else if (ans[i] > lion[i]) {
                        break;
                    }
                    else {
                        for (int i = 0; i < 11; i++) {
                            ans[i] = lion[i];
                        }
                        break;
                    }
                }
            }
        }
        mScore -= temp;
        return;
    }
    if (level > 10) {
        lion[10] += n - c;
        if (lScore > mScore) {
            if (big < lScore - mScore) {
                big = lScore - mScore;
                for (int i = 0; i < 11; i++) {
                    ans[i] = lion[i];
                }
            }
            else if (big == lScore - mScore) {
                for (int i = 10; i >= 0; i--) {
                    if (ans[i] == lion[i]) {
                        continue;
                    }
                    else if (ans[i] > lion[i]) {
                        break;
                    }
                    else {
                        for (int i = 0; i < 11; i++) {
                            ans[i] = lion[i];
                        }
                        break;
                    }
                }
            }
        }
        lion[10] -= n - c;
        return;
    }
    for (int i = 0; i <= n - c; i++) {
        lion[level] += i;
        if (lion[level] > info[level]) {
            lScore += (10 - level);
            sol(n, level + 1, c + i, info);
            lion[level] -= i;
            lScore -= (10 - level);
        }
        else {
            if (info[level] != 0) {
                mScore += (10 - level);
                sol(n, level + 1, c + i, info);
                lion[level] -= i;
                mScore -= (10 - level);
            }
            else {
                sol(n, level + 1, c + i, info);
            }
        }


    }
}

vector<int> solution(int n, vector<int> info) {

    sol(n, 0, 0, info);
    if (big == 0) {
        answer.push_back(-1);
        return answer;
    }
    else {
        for (int i = 0; i < 11; i++) {
            answer.push_back(ans[i]);
        }
    }

    return answer;
}