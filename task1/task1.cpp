#include <iostream>
using namespace std;

int main() {
    setlocale(LC_ALL, "rus");
    int n, m, start = 1;
    cout << "Введите длину массива: ";
    cin >> n;
    cout << "Введите длину шага: ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        return 0;
    }

    cout << "Полученный путь: ";

    while (true) {
        cout << start;
        start = (start + m - 2) % n + 1;  //формула нахождения пути
        if (start == 1) break;
    }
    return 0;
}