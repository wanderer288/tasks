
#include <iostream>
#include <fstream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    string f;
    int h;
    vector <int> nums;

    cout << "Введите путь для файла с массивом: ";
    cin >> f;
    fstream file(f);

    if (file.is_open()) {
        cout << "Доступ к файлу успешно получен" << endl << endl;
        while (!file.eof()) {
            file >> h;
            nums.push_back(h);
        }
    }
    else {
        cout << "Ошибка доступа к файлу" << endl;
        return 1;
    }

    if (nums.empty()) {
        cout << "Файл пуст" << endl;
    }

    sort(nums.begin(), nums.end());   //сортировка вектора по возрастанию
    int m = (nums.size() / 2), v;   //нахождение середины


    long long x = 0;   //количесиво шагов 

    for (int i = 0; i < nums.size(); i++) {
        v = nums[i];
        x += abs(v - m);    //вычисление количества шагов от v(элемента массива) до m(середины)
    }

    cout << "Количество шагов: " << x;

    return 0;
}
