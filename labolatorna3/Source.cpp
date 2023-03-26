#include <iostream>
using namespace std;

const int MAX_ROWS = 100;
const int MAX_COLS = 100;

class Table {
private:
    int data[MAX_ROWS][MAX_COLS];
    int numRows;
    int numCols;

public:
    Table(int rows, int cols) {
        numRows = rows;
        numCols = cols;
        for (int i = 0; i < numRows; i++) {  // Ітеруємось по кожному рядку
            for (int j = 0; j < numCols; j++) {  // Ітеруємось по кожному стовпцю
                data[i][j] = 0;  // Ініціалізуємо значення елемента нулем
            }
        }
    }

    void addRow() {
        if (numRows < MAX_ROWS) {  // Перевіряємо, щоб не перевищувався максимальний розмір рядків
            for (int i = numRows; i < numRows + 1; i++) {  // Додаємо один рядок до таблиці
                for (int j = 0; j < numCols; j++) {
                    data[i][j] = 0;  // Ініціалізуємо значення елемента нулем
                }
            }
            numRows++;  // Збільшуємо лічильник кількості рядків
        }
        else {
            cout << "Error: maximum number of rows exceeded." << endl;
        }
    }

    void addColumn() {
        if (numCols < MAX_COLS) {  // Перевіряємо, щоб не перевищувався максимальний розмір стовпців
            for (int i = 0; i < numRows; i++) {  // Додаємо один стовпець до кожного рядка таблиці
                data[i][numCols] = 0;  // Ініціалізуємо значення елемента нулем
            }
            numCols++;  // Збільшуємо лічильник кількості стовпців
        }
        else {
            cout << "Error: maximum number of columns exceeded." << endl;
        }
    }

    void deleteRow(int row) {
        if (row < 0 || row >= numRows) {  // Перевіряємо, щоб індекс рядка був коректним
            cout << "Error: invalid row index." << endl;
            return;
        }
        for (int i = row; i < numRows - 1; i++) {  // Копіюємо значення кожного елемента наступного рядка на поточний рядок
            for (int j = 0; j < numCols; j++) {
                data[i][j] = data[i + 1][j];
            }
        }
        numRows--;  // Зменшуємо лічильник


        int getElement(int row, int col) {
            if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
                cout << "Error: invalid row or column index." << endl;
                return -1;
            }
            return data[row][col];
        }

        void setElement(int row, int col, int value) {
            if (row < 0 || row >= numRows || col < 0 || col >= numCols) {
                cout << "Error: invalid row or column index." << endl;
                return;
            }
            data[row][col] = value;
        }

        void printTable() {
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    cout << data[i][j] << " ";
                }
                cout << endl;
            }
        }
    };
    int main() {
        Table t(3, 3);
        t.setElement(0, 0, 1);
        t.setElement(0, 1, 2);
        t.setElement(0, 2, 3);
        t.setElement(1, 0, 4);
        t.setElement(1, 1, 5);
        t.setElement(1, 2, 6);
        t.setElement(2, 0, 7);
        t.setElement(2, 1, 8);
        t.setElement(2, 2, 9);
        t.printTable();
        t.addRow();
        t.printTable();
        t.addColumn();
        t.printTable();
        t.deleteRow(1);
        t.printTable();
        return 0;
    }

