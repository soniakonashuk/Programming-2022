#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <vector>
#include "doctest.h"

using namespace std;

// Сортування вставками
void insertion_sort(vector<int>& arr) {
    // Перебираємо всі елементи починаючи з другого
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
        // Обираємо елемент для порівняння та вставки
        int key = arr[i];

        // Встановлюємо позицію перед попереднім елементом
        int j = i - 1;

        // Здійснюємо пошук позиції для вставки обраного елемента
        while (j >= 0 && arr[j] > key) {
            // Зсуваємо більші елементи на наступну позицію
            arr[j + 1] = arr[j];
            --j;
        }

        // Вставляємо поточний елемент на відповідне місце
        arr[j + 1] = key;
    }
}

int main() {
    // Приклад використання
    vector<int> lst = { 170, 45, 75, 90, 802, 24, 2, 66 };

    cout << "Unsorted list: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl;

    insertion_sort(lst);

    cout << "Sorted list: ";
    for (int num : lst) {
        cout << num << " ";
    }
    cout << endl << endl;


    // Запуск тестів
    doctest::Context context;
    int res = context.run();
    return res;
}

TEST_CASE("Сортування порожнього списку")
{
    vector<int> empty_lst;
    insertion_sort(empty_lst);
    CHECK(empty_lst.empty());
}

TEST_CASE("Сортування списку з одним елементом")
{
    vector<int> one_elem_lst = { 42 };
    insertion_sort(one_elem_lst);
    CHECK(one_elem_lst.size() == 1);
    CHECK(one_elem_lst[0] == 42);
}

TEST_CASE("Сортування списку з декількома елементами")
{
    vector<int> lst = { 170, 45, 75, 90, 802, 24, 2, 66 };
    insertion_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}

TEST_CASE("Сортування списку з від'ємними числами")
{
    vector<int> lst = { -170, 45, -75, 90, -802, 24, -2, 66 };
    insertion_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}

TEST_CASE("Сортування списку з повторюваними числами")
{
    vector<int> lst = { 170, 45, 75, 90, 802, 24, 2, 66, 45, 45, 45, 45, 45 };
    insertion_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}
