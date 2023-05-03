#include <iostream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

struct GasBill {
    string subscriber_name;
    int registered_persons;
    double amount_paid;
};

struct WaterBill {
    string subscriber_name;
    int last_meter_reading;
    double water_volume_paid;
    double amount_paid;
};
//функція порівняння для сортування 
bool gasBillComparator(const GasBill& a, const GasBill& b) {
    return a.registered_persons > b.registered_persons;
}//порівняння по полям 

bool waterBillComparator(const WaterBill& a, const WaterBill& b) {
    return a.subscriber_name < b.subscriber_name;
}

bool waterPaymentComparator(const WaterBill& a, const WaterBill& b) {
    return a.amount_paid > b.amount_paid;
}

int main() {
    deque<GasBill> gas_bills;
    deque<WaterBill> water_bills;

    ifstream infile("bills.txt");
    if (!infile.is_open()) {
        cerr << "Could not open file" << endl;
        return 1;
    }

    string line;
    while (getline(infile, line)) {
        size_t pos = line.find(": ");// провірка наявності : для розділення 
        if (pos == string::npos) continue;

        string bill_type = line.substr(0, pos);//витяг типа рахунку і данних рахунку
        string bill_data = line.substr(pos + 2);//пропустити 2 символи : і пробіл

        pos = bill_data.find(", ");//провірка наявності щоб розділити імя амонента і данні
        if (pos == string::npos) continue;

        string subscriber_name = bill_data.substr(0, pos); //витяг імені і інших данних 

        if (bill_type == "Gas bill") {
            int registered_persons = stoi(bill_data.substr(pos + 2));
            double amount_paid = stod(bill_data.substr(bill_data.find_last_of(", ") + 2));
            gas_bills.push_back({ subscriber_name, registered_persons, amount_paid });
        }
        else if (bill_type == "Water bill") {
            int last_meter_reading = stoi(bill_data.substr(pos + 2));//stoi перетворення до цілочисельних тип 
            pos = bill_data.find_last_of(", ");
            double water_volume_paid = stod(bill_data.substr(pos + 2));
            double amount_paid = stod(bill_data.substr(bill_data.find_last_of(", ") + 2));
            water_bills.push_back({ subscriber_name, last_meter_reading, water_volume_paid, amount_paid });
        }
    }
    infile.close();

    sort(gas_bills.begin(), gas_bills.end(), gasBillComparator);

    sort(water_bills.begin(), water_bills.end(), waterBillComparator);

    cout << "Gas bills:" << endl;
    for (auto bill : gas_bills) {
        cout << "Subscriber name: " << bill.subscriber_name << ", Registered persons: " << bill.registered_persons << ", Amount paid: " << bill.amount_paid << endl;
    }

    cout << "Water bills:" << endl;
    for (auto bill : water_bills) {
        cout << "Subscriber name: " << bill.subscriber_name << ", Last meter reading: " << bill.last_meter_reading << ", Water volume paid: " << bill.water_volume_paid << ", Amount paid: " << bill.amount_paid << endl;
    }

    ofstream gas_file("gas_bills.txt");
    if (!gas_file.is_open()) {
        cerr << "Unable to open gas_bills.txt file" << endl;
        return 1;
    }
    for (auto bill : gas_bills) {
        gas_file << bill.subscriber_name << "," << bill.registered_persons << "," << bill.amount_paid << endl;
    }
    gas_file.close();

}
//Винятки 