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

    cout << "請輸入 m 和 n 的值：";
    cin >> m >> n;

    // 開始計時
    clock_t START = clock();

    // 計算 Ackermann 函數
    long long result = ackermann(m, n);

    // 結束計時
    clock_t END = clock();

    // 計算花費的時間（以秒為單位）
    double timeSpent = static_cast<double>(END - START) / CLOCKS_PER_SEC;

    // 顯示結果和計算時間
    cout << "A(" << m << ", " << n << ") = " << result << "\n";

    // 判斷時間顯示方式
    if (timeSpent > 60) {
        int minutes = static_cast<int>(timeSpent / 60); // 取整數的分鐘數
        double seconds = timeSpent - (minutes * 60); // 剩餘的秒數
        cout << "進行運算所花費的時間：" << minutes << " 分 " << seconds << " 秒" << endl;
    } else {
        cout << "進行運算所花費的時間：" << timeSpent << " 秒" << endl;
    }

    return 0;
}

