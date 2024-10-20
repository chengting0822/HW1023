#include <iostream>
#include <ctime>  
using namespace std;

long long ackermann(long long m, long long n) {
    if (m == 0) {
        return n + 1;
    }
    if (n == 0) {
        return ackermann(m - 1, 1);
    }
    return ackermann(m - 1, ackermann(m, n - 1));
}

int main() {
    long long m, n;

    cout << "�п�J m �M n ���ȡG";
    cin >> m >> n;

    // �}�l�p��
    clock_t START = clock();

    // �p�� Ackermann ���
    long long result = ackermann(m, n);

    // �����p��
    clock_t END = clock();

    // �p���O���ɶ��]�H�����^
    double timeSpent = static_cast<double>(END - START) / CLOCKS_PER_SEC;

    // ��ܵ��G�M�p��ɶ�
    cout << "A(" << m << ", " << n << ") = " << result << "\n";

    // �P�_�ɶ���ܤ覡
    if (timeSpent > 60) {
        int minutes = static_cast<int>(timeSpent / 60); // ����ƪ�������
        double seconds = timeSpent - (minutes * 60); // �Ѿl�����
        cout << "�i��B��Ҫ�O���ɶ��G" << minutes << " �� " << seconds << " ��" << endl;
    } else {
        cout << "�i��B��Ҫ�O���ɶ��G" << timeSpent << " ��" << endl;
    }

    return 0;
}

