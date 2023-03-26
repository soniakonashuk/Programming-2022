#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include <list>
#include "doctest.h"

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
        auto it_row = data.begin();
        advance(it_row, row);
        auto it_col = it_row->begin();
        advance(it_col, col);
        *it_col = value;
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

// DocTest for Table::set()
// Input: set(1, 2, 7)
// Output: (no output, just sets value 7 at row 1, col 2)
// Check: get(1, 2) should return 7
TEST_CASE("test get method 1") {
    Table table(3, 4);
    table.set(1, 2, 7);
    CHECK(table.get(1, 2) == 7);
}

// DocTest for Table::get()
// Input: set(2, 3, 12), get(2, 3)
// Output: 12
// Check: (no additional check needed since we're directly testing get() output)
TEST_CASE("test get method 2") {
    Table table(3, 4);
    table.set(2, 3, 12);
    CHECK(table.get(2, 3) == 12);
}

// DocTest for Table::print()
// Input: set values at various positions and print the table
// Output: table displayed in console
// Check: visually inspect table output to ensure correct values and formatting
void test_print() {
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
}

int main() {
    test_print();
    return 0;
}