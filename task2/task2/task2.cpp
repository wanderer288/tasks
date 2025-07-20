

#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    double x0, y0, R; //координаты центра и радиус
    string f1, f2;  //пути к файлам

    cout << "Введите путь для файла с центром окружности и ее радиусом (файл 1): "; 
    cin >> f1;
    cout << "Введите путь для файла с координатами точек (файл 2) : ";
    cin >> f2;

    ifstream file1(f1);

    if (file1.is_open()) {   //проерка на успешное открытие файла
        cout<<"Доступ к файлу 1 успешно получен"<<endl;

        while (!file1.eof()) {
            file1 >> x0 >> y0 >> R;
        }
    }

    else {
        cout<<"Ошибка доступа к файлу 1"<<endl;
    }

    double R2 = R * R;
    
    file1.close();


    ifstream file2(f2);

    if (file2.is_open()) {

        cout << "Доступ к файлу 2 успешно получен" << endl;
        double x, y; // координаты точек

        while (!file2.eof()) {
            file2 >> x >> y;

            double D2 = pow(x - x0, 2) + pow(y - y0, 2);   //формула для определения места точки по отношению к окружности
            if (D2 == R2) cout << 0 << endl;   //точка лежит на окружности
            if (D2 < R2) cout << 1 << endl;    //точка лежит внутри окружности
            if (D2 > R2) cout << 2 << endl;    //точка лежит снаружи окружности
        }
    }

    else {
        cout << "Ошибка доступа к файлу 2" << endl;
    }

    file2.close();

    return 0;
}
