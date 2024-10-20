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

        // 輸出子集
        cout << "{ ";
        for (int k = 0; k < subsetSize; k++) {
            cout << subset[k] << " ";
        }
        cout << "}" << endl;
    }

    delete[] subset;
}

int main() {
    // 使用者輸入
    int number;
    cout << "輸入有幾個字元: ";
    cin >> number;

    char* array = new char[number]; // 動態配置陣列
    cout << "輸入字元: ";
    for (int i = 0; i < number; i++) {
        cin >> array[i]; // 讀取輸入
    }

    // 開始計時
    clock_t START = clock();

    // 生成子集
    generatePowerSet(array, number);

    // 結束計時
    clock_t END = clock();

    // 計算並顯示所花費的時間
    double timeSpent = static_cast<double>(END - START) / CLOCKS_PER_SEC;
    cout << "進行運算所花費的時間：" << timeSpent << " 秒" << endl;

    delete[] array;
    return 0;
}
