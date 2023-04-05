#include <iostream>
#include <string>
#include <ctime>

using namespace std;

// Клас для зберігання даних про товар
template <typename T>
class Product {
private:
    T item;
    time_t production_date;
    int expiration_days;
public:
    // Конструктор за замовчуванням
    Product() {
        this->expiration_days = 0;
        this->production_date = time(NULL);
    }

    // Конструктор
    Product(T item, int expiration_days) {
        this->item = item;
        this->production_date = time(NULL);
        this->expiration_days = expiration_days;
    }

    // Метод, який повертає дату кінцевого терміну придатності
    time_t get_expiration_date() {
        return production_date + (expiration_days * 24 * 60 * 60);
    }

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Product<T>& product) {
        os << "Item: " << product.item << endl;
        os << "Production date: " << ctime(&(product.production_date));
        os << "Expiration date: " << ctime(&(product.get_expiration_date()));
        return os;
    }

    // Оператор >>
    friend istream& operator>>(istream& is, Product<T>& product) {
        is >> product.item >> product.expiration_days;
        product.production_date = time(NULL);
        return is;
    }
};

// Структура Молоко
struct Milk {
    string name;
    float fat_content;

    // Оператор <<
    friend ostream& operator<<(ostream& os, const Milk& milk) {
        os << "Name: " << milk.name << endl;
        os << "Fat content: " << milk.fat_content << "%" << endl;
        return os;
    }

    // Оператор >>
    friend istream& operator>>(istream& is, Milk& milk) {
        is >> milk.name >> milk.fat_content;
        return is;
    }
};

int main() {
    // Масиви товарів зі шаблонними параметрами string та Milk
    Product<string> string_products[3] = {
        Product<string>("Bread", 2),
        Product<string>("Milk", 7),
        Product<string>("Cheese", 14)
    };

    Product<Milk> milk_products[2];
    for (int i = 0; i < 2; i++) {
        cout << "Enter milk " << i + 1 << " info:" << endl;
        cin >> milk_products[i];
    }

    // Виведення даних про товари
    for (int i = 0; i < 3; i++) {
        cout << string_products[i] << endl;
    }

    for (int i = 0; i < 2; i++) {
        cout << milk_products[i] << endl;
    }

    return 0;
}