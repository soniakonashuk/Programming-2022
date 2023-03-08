#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

// Оголошення абстрактного типу "телефон"
class Phone
{
    // публічні поля та методи
public:
    string name;
    string brand;
    double price;
    // конструктор
    Phone(string n, string b, double p) : name(n), brand(b), price(p) {}
    virtual ~Phone() {} // Віртуальний деструктор
};

// Похідний тип "мобільний телефон"
class MobilePhone : public Phone
{
public:
    string color;
    int memory;
    MobilePhone(string n, string b, double p, string c, int m) : Phone(n, b, p), color(c), memory(m) {}
};

// Похідний тип "радіотелефон"
class RadioPhone : public Phone
{
public:
    double radius;
    bool hasAnsweringMachine;
    RadioPhone(string n, string b, double p, double r, bool a) : Phone(n, b, p), radius(r), hasAnsweringMachine(a) {}
};

// Функція для зчитування даних з текстового файлу
vector<Phone*> readDataFromFile(string fileName)
{
    // створення вектора телефонів та зчитування файлу
    vector<Phone*> phones;
    // Зчитування з ФАЙЛУ ifstream - метод для зчитування з файлу
    ifstream inputFile(fileName);
    // is_open() - метод для перевірки чи файл відкрито
    if (inputFile.is_open())
    {
        string line;
        // getline() - метод для зчитування рядка з файлу
        while (getline(inputFile, line))
        {
            string name, brand;
            double price;
            // stringstream - клас для роботи з рядками
            if (fileName == "file1.txt")
            {
                string color;
                int memory;
                // stringstream - клас для роботи з рядками
                stringstream ss(line);
                // >> - оператор для зчитування з рядка
                ss >> name >> brand >> price >> color >> memory;
                phones.push_back(new MobilePhone(name, brand, price, color, memory));
            }
            else if (fileName == "file2.txt")
            {
                double radius;
                bool hasAnsweringMachine;
                stringstream ss(line);
                ss >> name >> brand >> price >> radius >> hasAnsweringMachine;
                phones.push_back(new RadioPhone(name, brand, price, radius, hasAnsweringMachine));
            }
        }

        // Закриття файлу
        inputFile.close();
    }
    return phones;
}

// Функція для сортування телефонів за ціною та виведення загальної суми
void sortPhonesByPrice(vector<Phone*> phones)
{
    double totalSum = 0.0;
    sort(phones.begin(), phones.end(), [](Phone* a, Phone* b)
        { return a->price < b->price; });
    ofstream outputFile("sortedPhonesByPrice.txt");
    if (outputFile.is_open())
    {
        for (Phone* p : phones)
        {
            totalSum += p->price;
            outputFile << p->name << ", " << p->brand << ", " << p->price << endl;
        }
        outputFile << "Total sum: " << totalSum << endl;
        outputFile.close();
    }
}

// Функція для виведення радіотелефонів з автовідповідачем
void printRadioPhonesWithAnsweringMachine(vector<Phone*> phones) {
    // offstream - метод для запису в файл
    ofstream outputFile("radioPhonesWithAnsweringMachine.txt");
    // is_open() - метод для перевірки чи файл відкрито
    if (outputFile.is_open())
    {
        // dynamic_cast - оператор для перетворення типів
        // Цикл for для перебору елементів вектора
        for (Phone* p : phones)
        {
            RadioPhone* r = dynamic_cast<RadioPhone*>(p);
            // Якщо r не пустий і має автовідповідач
            if (r && r->hasAnsweringMachine)
            {
                outputFile << p->name << ", " << p->brand << ", " << p->price << ", " << r->radius << ", " << r->hasAnsweringMachine << endl;
            }
        }
        outputFile.close();
    }
}

int main()
{
    // Зчитування даних з файлів
    vector<Phone*> phones1 = readDataFromFile("file1.txt");
    vector<Phone*> phones2 = readDataFromFile("file2.txt");


    // Об'єднання списків телефонів в один масив
    vector<Phone*> allPhones;
    allPhones.insert(allPhones.end(), phones1.begin(), phones1.end());
    allPhones.insert(allPhones.end(), phones2.begin(), phones2.end());

    // Сортування телефонів за ціною та виведення результатів у файл
    sortPhonesByPrice(allPhones);

    // Виведення радіотелефонів з автовідповідачем у файл
    printRadioPhonesWithAnsweringMachine(allPhones);

    // Видалення виділеної пам'яті
    for (Phone* p : allPhones)
    {
        delete p;
    }

    return 0;
}