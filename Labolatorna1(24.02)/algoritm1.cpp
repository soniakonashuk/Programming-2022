#define DOCTEST_CONFIG_IMPLEMENT

#include <iostream>
#include <vector>
#include "doctest.h"

using namespace std;

// Отримати значення розряду елемента за заданим порядком
int get_digit(int num, int digit_order) {
    return (num / digit_order) % 10;
}

// Сортування за розрядами
void radix_sort(vector<int>& lst) {
    if (lst.empty()) {
        return;
    }

    // Знайти максимальне число та визначити його кількість розрядів
    int max_num = lst[0];
    for (int i = 1; i < lst.size(); i++) {
        if (lst[i] > max_num) {
            max_num = lst[i];
        }
    }
    int digit_order = 1;
    while (max_num / digit_order > 0) {
        // Розділити елементи за значенням розряду
        vector<vector<int>> buckets(10);
        for (int i = 0; i < lst.size(); i++) {
            int digit = get_digit(lst[i], digit_order);
            buckets[digit].push_back(lst[i]);
        }
        // Об'єднати елементи в список
        lst.clear();
        for (int i = 0; i < 10; i++) {
            lst.insert(lst.end(), buckets[i].begin(), buckets[i].end());
        }
        // Перейти до наступного розряду
        digit_order *= 10;
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

    radix_sort(lst);

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
    radix_sort(empty_lst);
    CHECK(empty_lst.empty());
}

TEST_CASE("Сортування списку з одним елементом")
{
    vector<int> one_elem_lst = { 42 };
    radix_sort(one_elem_lst);
    CHECK(one_elem_lst.size() == 1);
    CHECK(one_elem_lst[0] == 42);
}

TEST_CASE("Сортування списку з декількома елементами")
{
    vector<int> lst = { 170, 45, 75, 90, 802, 24, 2, 66 };
    radix_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}

TEST_CASE("Сортування списку з від'ємними числами")
{
    vector<int> lst = { -170, 45, -75, 90, -802, 24, -2, 66 };
    radix_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}

TEST_CASE("Сортування списку з повторюваними числами")
{
    vector<int> lst = { 170, 45, 75, 90, 802, 24, 2, 66, 45, 45, 45, 45, 45 };
    radix_sort(lst);
    for (int i = 0; i < lst.size() - 1; i++) {
        CHECK(lst[i] <= lst[i + 1]);
    }
}