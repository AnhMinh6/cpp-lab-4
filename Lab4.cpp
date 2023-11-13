#include <iostream>
using namespace std;

void printPortions(int count, int portions[]) {
    cout << count << '\n';
    for (int i = 0; i < count; ++i) {
        cout << portions[i];
        if (i < count - 1)
            cout << ", ";
    }
    cout << '\n';
}

int main() {
    int n;
    cin >> n;

    int total_sum = n * (n + 1) / 2; // Сумма всех мисок

    // Проверяем, является ли сумма всех мисок четным числом
    if (total_sum % 2 == 1) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';

        int target_sum = total_sum / 2; // целевая сумма = общая сумма/2
        int current_sum_petya = 0;
        int current_sum_masha = 0;

        int l = 0; // Количество мини-порций у Пети
        int k = 0; // Количество мини-порций у Маши

        int max_masha_portions = n / 2;
        int* petya_portions = new int[max_masha_portions];
        int* masha_portions = new int[max_masha_portions];

        for (int i = n; i >= 1; --i) { 
            if (current_sum_petya + i <= target_sum) {
                petya_portions[l] = i;
                current_sum_petya += i;
                ++l;
            } else {
                masha_portions[k] = i;
                current_sum_masha += i;
                ++k;
            }
        }

        // Выводим количество мини-порций у Пети и их массы
        printPortions(l, petya_portions);

        // Выводим количество мини-порций у Маши и их массы
        printPortions(k, masha_portions);

        delete[] petya_portions;
        delete[] masha_portions;
    }

    return 0;
}
