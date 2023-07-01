/////////////////////////////////////////////////////////////////////////////////////////////
// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
// 아래 표준 입출력 예제 필요시 참고하세요.
// 표준 입력 예제
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int 변수 1개 입력받는 예제
// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
// cin >> g;                            // char 변수 1개 입력받는 예제
// cin >> var;                          // 문자열 1개 입력받는 예제
// cin >> AB;                           // long long 변수 1개 입력받는 예제
/////////////////////////////////////////////////////////////////////////////////////////////
// 표준 출력 예제
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int 변수 1개 출력하는 예제
// cout << b << " " << c;               // float 변수 2개 출력하는 예제
// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
// cout << g;                           // char 변수 1개 출력하는 예제
// cout << var;                         // 문자열 1개 출력하는 예제
// cout << AB;                          // long long 변수 1개 출력하는 예제
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <queue>
#include <vector>
using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for (test_case = 1; test_case <= T; ++test_case)
    {
        priority_queue<int>pq;
        int n, m;
        cin >> n;
        cin >> m;
        vector<int>list_n;
        vector<int>list_m;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            list_n.push_back(a);
        }
        for (int i = 0; i < m; i++) {
            int b;
            cin >> b;
            list_m.push_back(b);
        }


        if (n > m) {
            for (int i = 0; i <= n - m; i++) {
                int sum = 0;
                for (int j = 0; j < m; j++) {
                    sum += (list_n[i + j] * list_m[j]);
                }
                pq.push(sum);
            }
        }
        else {
            for (int i = 0; i <= m - n; i++) {
                int sum = 0;
                for (int j = 0; j < n; j++) {
                    sum += (list_n[j] * list_m[i + j]);
                }
                pq.push(sum);
            }
        }
        cout << "#" << test_case << " " << pq.top() << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}