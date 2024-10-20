#include <iostream>
#include <cmath>
#include <ctime> 

using namespace std;

void generatePowerSet(char array[], int n) {
    int total = static_cast<int>(pow(2, n));
    char* subset = new char[n];

    for (int i = 0; i < total; i++) {
        int subsetSize = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                subset[subsetSize++] = array[j];
            }
        }

        // ��X�l��
        cout << "{ ";
        for (int k = 0; k < subsetSize; k++) {
            cout << subset[k] << " ";
        }
        cout << "}" << endl;
    }

    delete[] subset;
}

int main() {
    // �ϥΪ̿�J
    int number;
    cout << "��J���X�Ӧr��: ";
    cin >> number;

    char* array = new char[number]; // �ʺA�t�m�}�C
    cout << "��J�r��: ";
    for (int i = 0; i < number; i++) {
        cin >> array[i]; // Ū����J
    }

    // �}�l�p��
    clock_t START = clock();

    // �ͦ��l��
    generatePowerSet(array, number);

    // �����p��
    clock_t END = clock();

    // �p�����ܩҪ�O���ɶ�
    double timeSpent = static_cast<double>(END - START) / CLOCKS_PER_SEC;
    cout << "�i��B��Ҫ�O���ɶ��G" << timeSpent << " ��" << endl;

    delete[] array;
    return 0;
}
