#include <iostream>
#include <string>
using namespace std;

class Monitor {
private:
    string name;
    double size;
    double price;

public:
    Monitor() : name("Monitor"), size(1.0), price(0) {}
    Monitor(string n, double s, double p) : name(n), size(s), price(p) {}
    Monitor(const Monitor& mon)
        : name(mon.name), size(mon.size), price(mon.price) {}

    friend ostream& operator<<(ostream& os, Monitor& mon) {
        os << mon.name << " Diagonal: " << mon.size << ". For " << mon.price << "$"
            << endl;

        return os;
    }
    friend istream& operator>>(istream& is, Monitor& mon) {
        cout << "Name: ";
        is >> mon.name;
        cout << "Size: ";
        is >> mon.size;
        cout << "Price: ";
        is >> mon.price;

        return is;
    }

    bool operator<(Monitor& mon) {
        if (price < mon.price) {
            return true;
        }
        return false;
    }
    bool operator>(Monitor& mon) {
        if (price > mon.price) {
            return true;
        }
        return false;
    }

    string get_name() { return name; }
    double get_size() { return size; }
};
Monitor* sort(Monitor* arr, int n) {
    for (int i = 0; i < n - 1; i++)

        for (int j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                Monitor temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
    return arr;
}

int main() {
    int n = 6;

    Monitor* mons = new Monitor[n];

    for (int i = 0; i < 3; i++) {
        cin >> mons[i];
    }
    Monitor m1;
    Monitor m2("LG", 25, 12500);
    Monitor m3(mons[0]);
    mons[3] = m1;
    mons[4] = m2;
    mons[5] = m3;
    mons = sort(mons, n);
    for (int i = 0; i < n; i++) {
        cout << mons[i];
    }

    cout << "Enter brand: ";
    string brand;
    cin >> brand;
    cout << endl;
    cout << "Enter size: ";
    double size;
    cin >> size;
    cout << endl;

    for (int i = 0; i < n; i++) {
        if (mons[i].get_name() == brand && mons[i].get_size() == size) {
            cout << mons[i];
        }
    }

    return 0;
}
