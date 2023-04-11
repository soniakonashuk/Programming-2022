#include <iostream>
#include <iomanip>//дозволяє використовувати функції для  виведення таблиці у відповідному форматі.
#include <sstream>
#include <cmath>
#include <functional>
#include <fstream>
#include <stdexcept>//бібліотека для обробки виключень

using namespace std;

string Modified(function<double(double)> operation, double* arr, int size)
{
    ostringstream stream;
    stream << setw(10) << "| i ";//встановлюємо розміри стовпців
    stream << setw(15) << "| a[i] ";
    stream << setw(20) << "| modified a[i] |" << endl;
    stream << setfill('-') << setw(46) << "" << setfill(' ') << endl;//встановлення символу заповнювача,- для розділення рядків в таблиці
    for (int i = 0; i < size; i++) {
        double modified = operation(arr[i]);
        stream << setw(10) << "| " << i << " ";
        stream << setw(15) << "| " << fixed << setprecision(2) << arr[i] << " ";
        stream << setw(20) << "| " << fixed << setprecision(2) << modified << " |" << endl;
    }
    return stream.str();
}

int main()
{
    try {//блок try - виконання коду, в якому можуть виникнути виключення
        // ввід масиву дійсних чисел
        double arr[] = { 1.5, 2.9, 3.8, 4.6, 5.7 };

        // 1) кожен елемент замінити на його квадрат
        auto square = [](double x) { return x * x; };
        string table1 = Modified(square, arr, 5);
        cout << "Modified table 1: " << endl << table1 << endl;

        // 2) кожен елемент a[i] замінити на sin(a[i]) + cos(a[i]) - tg(a[i])
        auto trigonometry = [](double x) { return
            sin(x) + cos(x) - tan(x); };
        string table2 = Modified(trigonometry, arr, 5);
        cout << "Modified table 2: " << endl << table2 << endl;

        // 3) кожен елемент замінити на найближче ціле число
        auto nearestInt = [](double x) { return round(x); };
        string table3 = Modified(nearestInt, arr, 5);
        cout << "Modified table 3: " << endl << table3 << endl;

        // запис результату у файл
        ofstream file("table.txt");
        if (!file.is_open()) {//перевірка, чи вдалося відкрити файл для запису
            throw runtime_error("Cannot open file for writing");
        }
        file << "Modified table 1: " << endl << table1 << endl;
        file << "Modified table 2: " << endl << table2 << endl;
        file << "Modified table 3: " << endl << table3 << endl;
        file.close();
    }
    catch (out_of_range& e) {//блок catch - обробка виключення, якщо вихід індексу за межі масиву
        cerr << "Error: " << e.what() << endl;
        cerr << "Index is out of range." << endl;
    }
    catch (invalid_argument& e) {//блок catch - обробка виключення, якщо неправильний ввід даних
        cerr << "Error: " << e.what() << endl;
        cerr << "Invalid argument." << endl;
    }
    catch (runtime_error& e) {//блок catch - обробка виключення, якщо не вдалося відкрити файл
        cerr << "Error: " << e.what() << endl;
        cerr << "Could not open file for writing." << endl;
    }

    return 0;
