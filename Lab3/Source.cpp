//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
//#include "doctest.h"
#include <iostream>
#include <list>

using namespace std;

class Table {
private:
    list<list<int>> data;
public:
    Table(int rows, int cols) {
        for (int i = 0; i < rows; i++) {
            data.push_back(list<int>(cols));
        }
    }

    void set(int row, int col, int value) {
        auto it_row = data.begin(); // отримує ітератор до 1 елемента 
        advance(it_row, row); // перший параметр початок ітератора,2- наскільки позицій треба здвинути ітератор
        auto it_col = it_row->begin(); // доступилися до елементу і тепер маємо ітератор на колонку
        advance(it_col, col);
        *it_col = value;// отримали значення елемента на який вказує ітератор
    }

    int get(int row, int col) {
        auto it_row = data.begin();
        advance(it_row, row);
        auto it_col = it_row->begin();
        advance(it_col, col);
        return *it_col;
    }

    void print() {
        for (auto& row : data) {
            for (auto& col : row) {
                cout << col << "\t";
            }
            cout << endl;
        }
    }
};

//
//TEST_CASE("TEST CASE 1") {
//    Table table(3, 4);
//    table.set(1, 2, 7);
//    CHECK(table.get(1, 2) == 7);
//}
//
//TEST_CASE("TEST CASE 2") {
//    Table table(3, 4);
//    table.set(2, 3, 12);
//    CHECK(table.get(2, 3) == 12);
//}

int main() {
    Table table(3, 4);
    table.set(0, 0, 1);
    table.set(0, 1, 2);
    table.set(0, 2, 3);
    table.set(0, 3, 4);
    table.set(1, 0, 5);
    table.set(1, 1, 6);
    table.set(1, 2, 7);
    table.set(1, 3, 8);
    table.set(2, 0, 9);
    table.set(2, 1, 10);
    table.set(2, 2, 11);
    table.set(2, 3, 12);
    table.print();
    return 0;
}