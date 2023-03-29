#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    string name;
    string address;
};

template <typename T>//повертає true, якщо перший аргумент повинен бути розташований перед другим при сортуванні.
void sort_array(T arr[], int n, bool (*compare)(T, T)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (compare(arr[j], arr[i])) {
                swap(arr[i], arr[j]);
            }
        }
    }
}

bool compare_int(int a, int b) {
    return a < b;
}

bool compare_string(string a, string b) {
    return a < b;
}

bool compare_person(Person a, Person b) {
    return a.name < b.name;
}

int main() {
    // Сортуємо масив цілих чисел
    int int_arr[] = { 10, 9, 8, 1, 6 };
    sort_array(int_arr, 5, compare_int);
    for (int i = 0; i < 5; i++) {
        cout << int_arr[i] << " ";
    }
    cout << endl;

    // сортуємо масив рядків
    string str_arr[] = { "apple", "banana", "strawberry", "orange", "gooseberry" };
    sort_array(str_arr, 5, compare_string);
    for (int i = 0; i < 5; i++) {
        cout << str_arr[i] << " ";
    }
    cout << endl;

    // Сортуємо Персона
    Person person_arr[] = {
        {"Sonia", "104 Lub St"},
        {"Andrii", "98 KO St"},
        {"Olena", "78 Petl St"},
        {"Marta", "45 Obr St"},
        {"Mariana", "105 Lub St"}
    };
    sort_array(person_arr, 5, compare_person);
    for (int i = 0; i < 5; i++) {
        cout << person_arr[i].name << " (" << person_arr[i].address << ")" << endl;
    }
    cout << endl;

    return 0;
}