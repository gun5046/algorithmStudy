#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

int arr[1000001];
int L[1000001];
int index[1000001];
int ans[1000001];

int main() {


    int n; cin >> n;
    int temp;
    int idx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        arr[i] = temp;
        if (idx == 0) {
            L[idx++] = temp;
            index[i] = 0; // first location = 0
        }
        else {
            if (L[idx - 1] < temp)
            {
                index[i] = idx;
                L[idx++] = temp;
            }
            else {
                index[i] = lower_bound(L, L + idx, temp) - L;
                L[lower_bound(L, L + idx, temp) - L] = temp;
            }
        }
    }
    int t = 0;
    cout << idx;
    for (int i = n; i >= 1; i--) {
        if (idx == index[i] + 1) {
            ans[t++] = arr[i];
            idx--;
        }
    }
    /*for (int i = t - 1; i >= 0; i--)
        cout << ans[i] << ' ';*/
}

/*
int arr[1000];
int dp[1000];
int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp[i] = 1;
    }

    for (int i = 0; i < n; i++) {
        int idx = i;
        int temp = i;
        if (dp[idx] != 1) continue;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[idx]) {
                if (dp[j] >= dp[idx] + 1) continue;
                dp[j] = dp[idx] + 1;
                temp = idx;
                idx = j;
            }
            else {
                if (arr[temp] < arr[j]) {
                    dp[j] = dp[idx];
                    idx = j;
                }
            }
        }
    }
    int Max = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > Max) {
            Max = dp[i];
        }
    }

    cout << Max;
}
*/