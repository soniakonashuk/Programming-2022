#include <iostream>
#include <string>
#include <vector>

using namespace std;


// generate account number
int generateAccountNumber() {
    return rand() % 1000000;
}

class Client {
private:
    string name;
    string address;
    string phoneNumber;

public:
    string getName() {
        return name;
    }

    void setName(string n) {
        name = n;
    }

    void setAdress(string addr) {
        address = addr;
    }

    void setPhoneNumber(string phnN) {
        phoneNumber = phnN;
    }
};

class BankAccount {
private:
    Client client;
    int accountNumber;
    double balance = 0;

public:
    void addToBalance(double amount) {
        balance += amount;
    }
    void subtractFromBalance(double amount) {
        balance -= amount;
    }

    void printBalance() {
        cout << "Balance: " << balance << endl;
    }

    void printAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout << "Name: " << client.getName() << endl;
    }

    void setClient(Client newClient) {
        client = newClient;
    }

    Client getClient() {
        return client;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    void setAccountNumber(int accNm) {
        accountNumber = accNm;
    }
};

int findAccountNumberByName(vector<BankAccount> accounts, string name) {
    for (int i = 0; i < accounts.size(); i++) {
        if (accounts[i].getClient().getName() == name) {
            return accounts[i].getAccountNumber();
        }
    }
}


int main() {
    // array with bank accounts
    vector<BankAccount> bankAccounts;

    // add 10 clients to array from terminal
    for (int i = 0; i < 3; i++) {
        Client client;
        string name;
        string address;
        string phoneNumber;

        cout << "Enter name: ";
        cin >> name;
        client.setName(name);

        cout << "Enter address: ";
        cin >> address;
        client.setAdress(address);

        cout << "Enter phone number: ";
        cin >> phoneNumber;
        client.setPhoneNumber(phoneNumber);
        bankAccounts[i].setClient(client);
        bankAccounts[i].setAccountNumber(generateAccountNumber());
    }

    // print all bank accounts
    for (int i = 0; i < bankAccounts.size(); i++) {
        bankAccounts[i].printAccountInfo();
    }

    //   cout << "Find you account number by name: ";
    //   string name;
    //   cin >> name;
    //   cout << "Account number: " << findAccountNumberByName(bankAccounts, name) << endl;
}