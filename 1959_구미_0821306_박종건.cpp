/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
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
       ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
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
    return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}