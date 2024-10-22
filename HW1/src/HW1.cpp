#include <iostream>
using namespace std;
long long temp[5][10000000]; 
long long  count1 = 0;
long long  count2 = 0;
long long ackermann1(long long m, long long n)//�@�뻼�j
{
    if (m == 0) {
        count2++;
        return n + 1;
    }
    if (n == 0) {
        count2++;
        return ackermann1(m - 1, 1);
    }
    count2++;
    return ackermann1(m - 1, ackermann1(m, n - 1));
}
long long ackermann(long long m, long long n) //�u�ƻ��j
{
    if (temp[m][n] != -1) {
        count1++;
        return temp[m][n];
    }
    if (m == 0) {
        count1++;
        return temp[m][n] = n + 1;
    }
    if (n == 0) {
        count1++;
        return temp[m][n] = ackermann(m - 1, 1);
    }
    count1++;
    return temp[m][n] = ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    long long m, n;

    //��l�� temp �}�C
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10000000; ++j) {
            temp[i][j] = -1;  
        }
    }

    cout << "�п�J m �M n ���ȡG";
    cin >> m >> n;
    // �p�� Ackermann ���
    long long result = ackermann(m, n);
    long long result1 = ackermann1(m, n);
    
    cout <<"�@�뻼�j:"<<endl<< "A(" << m << ", " << n << ") = " << result << "\n" << "�`�@���j:" << count1 << "��" << endl;
    cout << "�u�ƻ��j:" << endl << "A(" << m << ", " << n << ") = " << result1 << "\n" << "�`�@���j:" << count2 << "��" << endl;


    return 0;
}
