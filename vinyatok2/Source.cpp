#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

string translateToUkrainian(string name) {
    return "З днем народження, " + name + "!";
}

string translateToEnglish(string name) {
    return "Happy Birthday, " + name + "!";
}
string translateToGerman(string name) {
    return "Alles Gute zum Geburtstag, " + name + "!";
}
string greeting(string(*translator)(string), string name) {
    if (translator == nullptr) {
        throw logic_error("Translator function pointer is null.");
    }
    return (*translator)(name);
}

int main() {
    string name;
    string language;
    string(*translator)(string) = nullptr;

    try {
        cout << "Enter the name of the birthday person: ";
        getline(cin, name);

        cout << "Enter the language for the greeting (ukr, eng): ";
        cin >> language;

        if (language == "ukr") {
            translator = &translateToUkrainian;
        }
        else if (language == "eng") {
            translator = &translateToEnglish;
        }
        else if (language == "ger") {
            translator = &translateToGerman;
        }
        else {
            throw invalid_argument("An incorrect language was selected.");
        }

        string message = greeting(translator, name);

        ofstream outfile("greeting.txt");
        if (!outfile) {
            throw runtime_error("Could not open file.");
        }
        outfile << message;
        outfile.close();
        if (outfile.fail()) {
            throw runtime_error("Could not write to file.");
        }

        cout << "Greeting has been written to file greeting.txt." << endl;

    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    catch (const runtime_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }

    catch (const logic_error& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
   
    return 0;
}