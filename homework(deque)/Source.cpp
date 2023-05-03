
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

// Comparator function for sorting gas bills in descending order of registered persons
bool gasBillComparator(const GasBill& a, const GasBill& b) {
    return a.registered_persons > b.registered_persons;
}

// Comparator function for sorting water bills in alphabetical order of subscriber name
bool waterBillComparator(const WaterBill& a, const WaterBill& b) {
    return a.subscriber_name < b.subscriber_name;
}

// Comparator function for sorting water bills in descending order of amount paid
bool waterPaymentComparator(const WaterBill& a, const WaterBill& b) {
    return a.amount_paid > b.amount_paid;
}

int main() {
    deque<GasBill> gas_bills;
    deque<WaterBill> water_bills;

    try {
        ifstream infile("bills.txt");
        if (!infile.is_open()) {
            throw runtime_error("Could not open file");
        }
        string line;
        while (getline(infile, line)) {
            // Split the line into fields
            size_t pos = line.find(":");
            string bill_type = line.substr(0, pos);
            string bill_data = line.substr(pos + 2);
            pos = bill_data.find(", ");
            string subscriber_name = bill_data.substr(0, pos);

            if (bill_type == "Gas bill") {
                // Parse gas bill data and add to gas_bills deque
                int registered_persons = stoi(bill_data.substr(pos + 2));
                double amount_paid = stod(bill_data.substr(bill_data.find_last_of(", ") + 2));
                gas_bills.push_back({ subscriber_name, registered_persons, amount_paid });
            }
            else if (bill_type == "Water bill") {
                // Parse water bill data and add to water_bills deque
                int last_meter_reading = stoi(bill_data.substr(pos + 2));
                pos = bill_data.find_last_of(", ");
                double water_volume_paid = stod(bill_data.substr(pos + 2));
                double amount_paid = stod(bill_data.substr(bill_data.find_last_of(", ") + 2));
                water_bills.push_back({ subscriber_name, last_meter_reading, water_volume_paid, amount_paid });
            }
        }
    }
    catch (exception& e) {
        cout << "Error: " << e.what() << endl;
    }

    // Sort gas bills in descending order of registered persons
    sort(gas_bills.begin(), gas_bills.end(), gasBillComparator);

    // Sort water bills in alphabetical order of subscriber name
    sort(water_bills.begin(), water_bills.end(), waterBillComparator);

    // Print the contents of the gas_bills deque
    cout << "Gas bills:" << endl;
    for (auto bill : gas_bills) {
        cout << "Subscriber name: " << bill.subscriber_name << ", Registered persons: " << bill.registered_persons << ", Amount paid: " << bill.amount_paid << endl;
    }

    // Print the contents of the water_bills deque
    cout << "Water bills:" << endl;
    for (auto bill : water_bills) {
        cout << "Subscriber name: " << bill.subscriber_name << ", Last meter reading: " << bill.last_meter_reading << ", Water volume paid: " << bill.water_volume_paid << ", Amount paid: " << bill.amount_paid << endl;
    }

    // Write the gas bills to a file
    try {
        ofstream gas_file("gas_bills.txt");
        if (!gas_file.is_open()) {
            throw runtime_error("Unable to open gas_bills.txt file");
        }
        for (auto bill : gas_bills) {
            gas_file << bill.subscriber_name << "," << bill.registered_persons << "," << bill.amount_paid << endl;
        }
        gas_file.close();
    }
    catch (exception& e) {
        cerr << "Error occurred: " << e.what() << endl;
    }

    // Write the water bills to a file
    try {
        ofstream water_file("water_bills.txt");
        if (!water_file.is_open()) {
            throw runtime_error("Unable to open water_bills.txt file");
        }
        for (auto bill : water_bills) {
            water_file << bill.subscriber_name << "," << bill.last_meter_reading << "," << bill.water_volume_paid << "," << bill.amount_paid << endl;
        }
        water_file.close();
    }
    catch (exception& e) {
        cerr << "Error occurred: " << e.what() << endl;
    }

    // Sort water bills in descending order of amount paid
    sort(water_bills.begin(), water_bills.end(), waterPaymentComparator);

    // Write the top 5 water payments to a file
    try {
        ofstream top_water_file("top_water_payments.txt");
        if (!top_water_file.is_open()) {
            throw runtime_error("Unable to open top_water_payments.txt file");
        }
        int count = 0;
        for (auto bill : water_bills) {
            if (count == 5) break;
            top_water_file << bill.subscriber_name << "," << bill.last_meter_reading << "," << bill.water_volume_paid << "," << bill.amount_paid << endl;
            count++;
        }
        top_water_file.close();
    }
    catch (exception& e) {
        cerr << "Error occurred: " << e.what() << endl;
    }

    return 0;
}