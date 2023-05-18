#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
    ifstream inputFile("input.txt");

    if (!inputFile) {
        cout << "Can not open the file." << endl;
        return 1;
    }

    vector<string> words;
    string word;

    while (inputFile >> word) {
        words.push_back(word);
    }
    inputFile.close();

    vector<string> sameLetterWords;
    unordered_set<char> uniqueCharacters;

    // слова, що починаються і закінчуються на одну і ту ж букву в інший контейнер
    for (const string& w : words) {
        if (w.front() == w.back()) {
            sameLetterWords.push_back(w);
        }

        // Додавання унікальних символів до контейнера
        for (char c : w) {
            uniqueCharacters.insert(c);
        }
    }

    cout << "Words that start and end with the same letter:" << endl;
    for (const string& w : sameLetterWords) {
        cout << w << endl;
    }
    cout << "All symbols without repetitions:" << endl;
    for (char c : uniqueCharacters) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}
