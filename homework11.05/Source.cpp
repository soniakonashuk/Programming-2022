#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    ifstream file("input.txt");

    map<char, vector<int>> letters;

    string line;
    char* p;
    while (getline(file, line)) {
        char letter = line[0];
        string num;
        vector<int> positions;
        int j = 1, len = 1;
        for (int i = 2; i < line.length(); i++) {
            if (line[i] == ',') {
                positions.push_back(strtol(num.c_str(), &p, 10));
                num.resize(1, ' ');
                j = 1;
                len = 1;
            }
            else {
                len++;
                num.resize(len, ' ');
                num[j] = line[i];
                j++;
            }
        }
        letters[letter] = positions;
    }

    file.close();

    // Створення рядка з повним текстом 
    string text;
    for (auto letter_positions : letters) {
        char letter = letter_positions.first;
        for (int position : letter_positions.second) {
            if (position > text.length()) {
                text.resize(position + 1, ' ');
            }
            text[position] = letter;
            cout << letter << endl;
        }
    }

   
    ofstream file1("output1.txt");

    // Запис перших 10 символів тексту
    cout << text.substr(0, 10);
    file1 << text.substr(0, 10);
    file1.close();

    // Створення списку унікальних букв у тексті
    vector<char> unique_letters;
    for (auto letter_positions : letters) {
        unique_letters.push_back(letter_positions.first);
    }
    sort(unique_letters.begin(), unique_letters.end());

    //файл для посортованих за алфавітом
    ofstream file2("output2.txt");
    for (char letter : unique_letters) {
        file2 << letter << endl;
    }

    file2.close();

    return 0;
}