#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

// Функціональний об'єкт для заміни додатніх чисел на максимальний елемент
struct Fun
{
    double max_element;

    Fun(double max) : max_element(max) {}

    double operator()(double num) const
    {
        if (num > 0)
            return max_element;
        else
            return num;
    }
};

void f(vector<double>& l1, vector<double>& l2)
{
    // Завдання А
    double max = *max_element(l2.begin(), l2.end());
    transform(l1.begin(), l1.end(), l2.begin(), Fun(max));

    // Завдання Б
    double sum = accumulate(l2.begin(), l2.end(), 0.0);

    cout << "l1: ";
    for (const auto& element : l1) {
        cout << element << " ";
    }
    cout << endl;

    cout << "l2: ";
    for (const auto& element : l2) {
        cout << element << " ";
    }
    cout << endl;

    cout << "Sum of elements in l2: " << sum << endl;
}

int main()
{
    vector<double> l1 = { 1.5, -2.3, 3.7, -4.1 };
    vector<double> l2 = { 5.2, -6.4, 7.8, -8.9 };

    f(l1, l2);

    return 0;
}
