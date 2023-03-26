#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

class Stack {

private:
    static const int MAX_SIZE = 100;
    int data_[MAX_SIZE];
    int top_;
    int size_;

public:
    Stack() : top_(-1), size_(0) {}

    void push(int value) {
        if (size_ >= MAX_SIZE) {
            std::cout << "Stack overflow" << std::endl;
            return;
        }
        data_[++top_] = value;
        ++size_;
    }

    void pop() {
        if (size_ <= 0) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        --top_;
        --size_;
    }

    int top() const {
        if (size_ <= 0) {
            std::cout << "Stack is empty" << std::endl;
            return -1;
        }
        return data_[top_];
    }

    bool empty() const {
        return size_ == 0;
    }

    int size() const {
        return size_;
    }

};

TEST_CASE("Test case 1") {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    CHECK(s.top() == 1);
    CHECK(s.size() == 1);
    CHECK(!s.empty());
}

TEST_CASE("Test case 2") {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();
    s.pop();
    s.pop();
    CHECK(s.top() == -1);
    CHECK(s.size() == 0);
    CHECK(s.empty());
}

TEST_CASE("Test case 3") {
    Stack s;
    s.push(1);
    s.pop();
    CHECK(s.top() == -1);
    CHECK(s.size() == 0);
    CHECK(s.empty());
}

/*#include <iostream>
#include <stack>

int main() {
    std::stack<int> s;

    // Додаємо елементи до стеку
    s.push(1);
    s.push(2);
    s.push(3);

    // Виводимо елементи стеку у зворотньому порядку
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }

    return 0;
}
*/