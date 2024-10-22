#include <iostream>
#include <cmath>

using namespace std;

void generatePowerSet(char array[], int n) {
    int total = static_cast<int>(pow(2, n));
    char* subset = new char[n];
    int totalLoopCount = 0; // �p�ƾ��A�O���`�j�馸��

    for (int i = 0; i < total; i++) {
        totalLoopCount++; // �C���i�J�~�h�j��ɼW�[�p��
        int subsetSize = 0;
        for (int j = 0; j < n; j++) {
            totalLoopCount++; // �C���i�J���h�j��ɼW�[�p��
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

    cout << "�`�@����F " << totalLoopCount << " ���j��C" << endl; // ��X�`�j�馸��

    delete[] subset;
}

int main() {
    // �ϥΪ̿�J
    int number;
    cout << "��J���X�Ӥ���: ";
    cin >> number;

    char* array = new char[number]; // �ʺA�t�m�}�C
    cout << "��J"<<number<<"�Ӥ���:";
    for (int i = 0; i < number; i++) {
        cin >> array[i]; // Ū����J
    }
    // �ͦ��l��
    generatePowerSet(array, number);

    delete[] array;
    return 0;
}
