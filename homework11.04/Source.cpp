#include <iostream>
using namespace std;
template <typename T>
T* split_array(const T arr[], const int size, int& new_size) {
    // Перевірка, чи масив має хоча б один елемент
    if (size < 1) {
        throw invalid_argument("Масив повинен містити хоча б один елемент!");
    }

    // Останній елемент масиву
    const T pivot = arr[size - 1];

    T* greater = new T[size - 1];
    T* lesser = new T[size - 1];
    int greater_size = 0;
    int lesser_size = 0;

    // Розділення масиву на два - елементи, які більші за pivot і ті, які менші чи рівні йому
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > pivot) {
            greater[greater_size++] = arr[i];
        }
        else {
            lesser[lesser_size++] = arr[i];
        }
    }

    // Повернення масиву з меншою кількістю елементів
    if (greater_size < lesser_size) {
        new_size = greater_size;
        delete[] lesser;
        return greater;
    }
    else {
        new_size = lesser_size;
        delete[] greater;
        return lesser;
    }
}

int main() {
    // Приклад для масиву цілих чисел
    int int_arr[] = { 7, 2, 8, 9, 1, 6, 4 };
    const int int_size = sizeof(int_arr) / sizeof(int_arr[0]);

    int new_int_size;
    try {
        int* result = split_array(int_arr, int_size, new_int_size);

        cout << "Елементи масиву з меншою кількістю елементів: ";
        for (int i = 0; i < new_int_size; i++) {
           cout << result[i] << " ";
        }
        cout << endl;

        delete[] result;
    }
    catch (const invalid_argument& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    // Приклад для масиву рядків
    string str_arr[] = { "apple", "banana", "orange", "strawberry", "pear" };
    const int str_size = sizeof(str_arr) / sizeof(str_arr[0]);
    //винятки
    int new_str_size;
    try {
        string* result = split_array(str_arr, str_size, new_str_size);

        cout << "Елементи масиву з меншою кількістю елементів: ";
        for (int i = 0; i < new_str_size; i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        delete[] result;
    }
    catch (const invalid_argument& e) {
        cerr << "Помилка: " << e.what() << endl;
    }

    return 0;
}


