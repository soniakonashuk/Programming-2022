#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main() {
    list<char> sequence;
    char c;
    while (cin.get(c)) { 
        if (c == '\n') break; // Припинення вводу при введенні нового рядка
        sequence.push_back(c); // Додавання символу до списку
    }
    auto comma_pos = find(sequence.begin(), sequence.end(), ','); 
    if (comma_pos != sequence.end()) { 
        sequence.erase(sequence.begin(), comma_pos); // Видалення частини перед першою комою
        auto dot_pos = find(sequence.begin(), sequence.end(), '.'); // Пошук позиції першої крапки
        if (dot_pos != sequence.end()) { 
            replace(dot_pos, sequence.end(), '3', '+'); // Заміна цифри 3 на +
        }
    }
    sequence.remove(','); // Видалення 
    for (auto it = sequence.begin(); it != sequence.end(); ++it) { // Вивід результуючої послідовності
        cout << *it;
    }
    cout << endl;
    return 0;
}
