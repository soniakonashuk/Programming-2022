
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

class Computer
{
public:
    string firm;
    double price;
    virtual void print() = 0; // віртуальний метод, що дозволяє вивести інформацію про комп'ютер
};

class Desktop : public Computer
{
public:
    string type;
    string processor;
    void print() override
    {
        cout << "Firm: " << firm << ", Type: Desktop, Price: " << price << ", Processor: " << processor << endl;
    }
};

class Laptop : public Computer
{
public:
    double diagonal;
    int memory;
    void print() override
    {
        cout << "Firm: " << firm << ", Type: Laptop, Price: " << price << ", Diagonal: " << diagonal << ", Memory: " << memory << endl;
    }
};

int main()
{
    vector<Computer*> computers; // масив, що містить вказівники на об'єкти класів Computer, Desktop і Laptop

    ifstream input("computers.txt"); // відкриття файлу для зчитування даних
    if (!input)
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    while (!input.eof())
    { // зчитування даних з файлу
        string type;
        input >> type;

        if (type == "Desktop")
        {
            Desktop* desktop = new Desktop();
            input >> desktop->firm >> desktop->price >> desktop->type >> desktop->processor;
            computers.push_back(desktop);
        }
        else if (type == "Laptop")
        {
            Laptop* laptop = new Laptop();
            input >> laptop->firm >> laptop->price >> laptop->diagonal >> laptop->memory;
            computers.push_back(laptop);
        }
    }

    input.close(); // закриття файлу

    // сортування комп'ютерів за ціною
    sort(computers.begin(), computers.end(), [](Computer* a, Computer* b)
        { return a->price < b->price; });

    ofstream output("output.txt"); // відкриття файлу для запису даних
    if (!output)
    {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    // виведення комп'ютерів відсортованих за ціною
    for (auto computer : computers)
    {
        computer->print();
        output << computer->firm << " " << computer->price << endl;
    }

    // обчислення загальної вартості всіх ноутбуків
    double total_laptop_price = accumulate(computers.begin(), computers.end(), 0.0, [](double acc, Computer* computer)
        {
            if (dynamic_cast<Laptop*>(computer)) {
                return acc + computer->price;
            }
            else {
                return acc;
            } });

    output << "Total laptop price: " << total_laptop_price << endl;

    // виведення стаціонарних комп'ютерів зад
    output << "Enter a firm to display its desktop computers: ";
    string firm;
    cin >> firm;

    // виведення стаціонарних комп'ютерів заданої фірми
    for (auto computer : computers)
    {
        Desktop* desktop = dynamic_cast<Desktop*>(computer);
        if (desktop && desktop->firm == firm)
        {
            desktop->print();
            output << desktop->firm << " " << desktop->price << " " << desktop->type << " " << desktop->processor << endl;
        }
    }

    output.close(); // закриття файлу

    // видалення об'єктів з пам'яті
    for (auto computer : computers)
    {
        delete computer;
    }

    return 0;
}