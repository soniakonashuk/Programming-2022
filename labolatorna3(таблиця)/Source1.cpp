#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
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


TEST_CASE('TEST CASE 1') {
    Table table(3, 4);
    table.set(1, 2, 7);
    //CHECK(table.get(1, 2) == 7);
}

TEST_CASE("TEST CASE 2") {
    Table table(3, 4);
    table.set(2, 3, 12);
    //CHECK(table.get(2, 3) == 12);
}

//int main() {
//    return 0;
//}