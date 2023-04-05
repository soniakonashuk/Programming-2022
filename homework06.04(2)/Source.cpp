#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Функція, яка вітає іменинника заданою мовою
string Greeting(string(*translator)(string), string name) {
    string greeting = translator("Happy birthday") + ", " + name + "!";
    return greeting;
}

// Функції-перекладачі
string TranslateToEnglish(string text) {
    return text;
}

string TranslateToUkrainian(string text) {
    if (text == "Happy birthday") {
        return "З днем народження!";
    }
    else {
        return text;
    }
}

string TranslateToGerman(string text) {
    if (text == "Happy birthday") {
        return "Alles Gute zum Geburtstag!";
    }
    else {
        return text;
    }
}

int main() {
    string name, language;
    cout << "Enter the name of the birthday person: ";
    cin >> name;
    cout << "Choose a language for the greeting (English, Ukrainian, German): ";
    cin >> language;

    string(*translator)(string); // Вказівник на функцію
    if (language == "English") {
        translator = &TranslateToEnglish;
    }
    else if (language == "Ukrainian") {
        translator = &TranslateToUkrainian;
    }
    else if (language == "German") {
        translator = &TranslateToGerman;
    }
    else {
        cout << "Invalid language choice.";
        return 0;
    }

    string greeting = Greeting(translator, name);
    ofstream outfile("greeting.txt");
    outfile << greeting << endl;
    outfile.close();

    cout << "Greeting saved to greeting.txt." << endl;

    return 0;
}
