#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

class Stack {
private:
    int top;            // змінна, яка зберігає індекс верхнього елементу
    int items[MAX_SIZE]; // масив, який зберігає елементи стеку
public:
    Stack() {
        top = -1;
    }
    bool is_empty() {
        return top == -1;
    }
    bool is_full() {
        return top == MAX_SIZE - 1;
    }
    void push(int item) {
        if (is_full()) {
            cout << "Stack overflow" << endl;
            return;
        }
        top++;
        items[top] = item;
    }
    int pop() {
        if (is_empty()) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        int item = items[top];
        top--;
        return item;
    }
    int peek() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return items[top];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    cout << s.pop() << endl;    // 3
    cout << s.peek() << endl;   // 2
    s.push(4);
    cout << s.pop() << endl;    // 4
    cout << s.pop() << endl;    // 2
    cout << s.pop() << endl;    // 1
    cout << s.pop() << endl;    // Stack underflow
    return 0;
}