#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <Windows.h>

using namespace std;

int main() {

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Введіть елементи масиву:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_elem = *max_element(arr.begin(), arr.end());
    cout << "Максимальний елемент масиву: " << max_elem << endl;

    int min_elem = *min_element(arr.begin(), arr.end());
    cout << "Мінімальний елемент масиву: " << min_elem << endl;

    int last_positive_index = -1;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            last_positive_index = i;
        }
    }

    int sum = 0;
    if (last_positive_index != -1) {
        for (int i = 0; i < last_positive_index; ++i) {
            sum += arr[i];
        }
        cout << "Сума елементів до останнього додатнього: " << sum << endl;
    }
    else {
        cout << "У масиві немає додатніх елементів" << endl;
    }

    int a, b;
    cout << "Введіть межі інтервалу [a, b]: ";
    cin >> a >> b;

    if (a > b) {
        swap(a, b);
    }

    int write_index = 0;
    for (int i = 0; i < n; ++i) {
        int abs_val = abs(arr[i]);
        if (abs_val < a || abs_val > b) {
            arr[write_index++] = arr[i];
        }
    }

    for (int i = write_index; i < n; ++i) {
        arr[i] = 0;
    }

    cout << "Масив після стиснення:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}