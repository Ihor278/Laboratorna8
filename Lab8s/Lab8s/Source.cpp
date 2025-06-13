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
    cout << "������ ������� �������� ������: ";
    cin >> n;

    vector<int> arr(n);
    cout << "������ �������� ������:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int max_elem = *max_element(arr.begin(), arr.end());
    cout << "������������ ������� ������: " << max_elem << endl;

    int min_elem = *min_element(arr.begin(), arr.end());
    cout << "̳�������� ������� ������: " << min_elem << endl;

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
        cout << "���� �������� �� ���������� ����������: " << sum << endl;
    }
    else {
        cout << "� ����� ���� ������� ��������" << endl;
    }

    int a, b;
    cout << "������ ��� ��������� [a, b]: ";
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

    cout << "����� ���� ���������:\n";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}