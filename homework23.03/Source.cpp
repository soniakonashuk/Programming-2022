#include <iostream>
#include <utility>//для того щоб розглядати 2 об'єкта як 1
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
const bool USE_DEFAULT_VALUES = false;
const string WATER = "WATER";
const string LAND = "LAND";
const string AMPHIBIAN = "AMPHIBIAN";

class Transport {
private:
    string name;
    int engineVolume;
    string type;
public:
    Transport(string name, int engineVolume, string type) {
        this->name = std::move(name);
        this->engineVolume = engineVolume;
        this->type = std::move(type);
    }

     virtual string getName() const {
        return name;
    }

    virtual int getEngineVolume() const {
        return engineVolume;
    }

    string getType() const {
        return type;
    }

    friend ostream& operator<<(ostream& os, const Transport& transport) {
        os << transport.getType() + " TRANSPORT:" << endl;
        os << "    - GENERAL INFO: " << endl;
        os << "        - Name: " << transport.getName() << endl;
        os << "        - Engine volume: " << transport.getEngineVolume() << endl;
        return os;
    }

    virtual bool operator<(Transport& transport) {
        return name < transport.name;
    }
};

class WaterTransport : public virtual Transport {
private:
    string typeOfWater;
    int maxSpeedInWater;
public:
    WaterTransport(string name, int engineVolume, string typeOfWater, int maxSpeedInWater) :
        Transport(std::move(name), engineVolume, WATER) {
        this->typeOfWater = std::move(typeOfWater);
        this->maxSpeedInWater = maxSpeedInWater;
    }

    string getTypeOfWater() const {
        return typeOfWater;
    }

    int getMaxSpeedInWater() const {
        return maxSpeedInWater;
    }

    friend ostream& operator<<(ostream& os, const WaterTransport& water_transport) {
        os << static_cast<Transport>(water_transport);
        os << "    - WATER SPECIFIC INFO: " << endl;
        os << "        - Type of water: " << water_transport.getTypeOfWater() << endl;
        os << "        - Max speed in water: " << water_transport.getMaxSpeedInWater() << endl;
        return os;
    }
};

class LandTransport : public virtual Transport {
private:
    int maxSpeedOnLand;
    int numberOfSeats;
public:
    LandTransport(string name, int engineVolume, int maxSpeedOnLand, int numberOfSeats) :
        Transport(std::move(name), engineVolume, LAND) {
        this->maxSpeedOnLand = maxSpeedOnLand;
        this->numberOfSeats = numberOfSeats;
    }
     int getMaxSpeedOnLand() const {
        return maxSpeedOnLand;
    }

      int getNumberOfSeats() const {
        return numberOfSeats;
    }

    friend ostream& operator<<(ostream& os, const LandTransport& land_transport) {
        os << static_cast<Transport>(land_transport);
        os << "    - LAND SPECIFIC INFO: " << endl;
        os << "        - Max speed on land: " << land_transport.getMaxSpeedOnLand() << endl;
        os << "        - Number of seats: " << land_transport.getNumberOfSeats() << endl;
        return os;
    }
};

class AmphibianTransport : public WaterTransport, public LandTransport {
private:
    int maxHoursInWater;
    int maxHoursOnLand;
public:
    AmphibianTransport(
        const string& name,
        int engineVolume,
        string typeOfWater,
        int maxSpeedInWater,
        int maxSpeed,
        int numberOfSeats,
        int maxHoursInWater,
        int maxHoursOnLand) :
        Transport(name, engineVolume, AMPHIBIAN),
        WaterTransport(name, engineVolume, std::move(typeOfWater), maxSpeedInWater),
        LandTransport(name, engineVolume, maxSpeed, numberOfSeats) {
        this->maxHoursInWater = maxHoursInWater;
        this->maxHoursOnLand = maxHoursOnLand;
    }

   int getMaxHoursInWater() const {
        return maxHoursInWater;
    }

   int getMaxHoursOnLand() const {
        return maxHoursOnLand;
    }

    friend ostream& operator<<(ostream& os, const AmphibianTransport& amphibian_transport) {
        os << static_cast<Transport>(amphibian_transport);
        os << "    - WATER SPECIFIC INFO: " << endl;
        os << "        - Type of water: " << amphibian_transport.getTypeOfWater() << endl;
        os << "        - Max speed in water: " << amphibian_transport.getMaxSpeedInWater() << endl;
        os << "    - LAND SPECIFIC INFO: " << endl;
        os << "        - Max speed on land: " << amphibian_transport.getMaxSpeedOnLand() << endl;
        os << "        - Number of seats: " << amphibian_transport.getNumberOfSeats() << endl;
        os << "    - AMPHIBIAN SPECIFIC INFO: " << endl;
        os << "        - Max hours in water: " << amphibian_transport.getMaxHoursInWater() << endl;
        os << "        - Max hours on land: " << amphibian_transport.getMaxHoursOnLand() << endl;
        return os;
    }
};


Transport* promptForTransportItem();

int main() {
    //вектор транспортів
    vector<Transport*> transports;

    // перевірка чи юзер хоче використовувати дефолтне значення
    if (USE_DEFAULT_VALUES) {
        //додаємо 10 транспортів
        transports = {
            new WaterTransport("Boat", 150, "Ocean", 100),
            new WaterTransport("Submarine", 250, "Ocean", 200),
            new LandTransport("Truck", 350, 350, 3),
            new LandTransport("All-terrain vehicle", 399, 399, 5),//всюдихід
            new AmphibianTransport("Amphibian", 500, "Ocean", 500, 500, 5, 5, 5),
            new LandTransport("Bus", 700, 700, 7),
            new WaterTransport("Byferry", 900, "Ocean", 900),//паром
            new WaterTransport("Icebreaker", 800, "Ocean", 800),
            new LandTransport("Motorcycle", 400, 400, 9),
            new LandTransport("Car", 850, 850, 1)
        };
    }
    else {
        const int TRANSPORT_ITEMS_COUNT = 10;
        for (int i = 0; i < TRANSPORT_ITEMS_COUNT; i++) {
            cout << "=============================\n";
            cout << "Adding transport item " << i + 1 << " of " << TRANSPORT_ITEMS_COUNT << "\n";
            cout << "=============================\n\n";

           //добавляємо транспорт у вектор
            transports.push_back(promptForTransportItem());

            cout << "\n\n\n";
        }
    }

    // сортуємо транспорт за назвою
    sort(transports.begin(), transports.end(), [](const Transport* a, const Transport* b) {
        auto* aCasted = const_cast<Transport*>(a);
        auto* bCasted = const_cast<Transport*>(b);
        return *aCasted < *bCasted;
        });

    // Виводимо весь трансопрт
    cout << "=================\n";
    cout << "SORTED TRANSPORT:\n";
    cout << "=================\n\n";
    for (const auto& transport : transports) {
        //перевіряємо чи водний,наземний,амфібія
        if (const auto* amphibianTransport = dynamic_cast<AmphibianTransport*>(transport)) {
            cout << *amphibianTransport << endl;
        }
        else if (const auto* waterTransport = dynamic_cast<WaterTransport*>(transport)) {
            cout << *waterTransport << endl;
        }
        else if (const auto* landTransport = dynamic_cast<LandTransport*>(transport)) {
            cout << *landTransport << endl;
        }
    }
    cout << "\n\n";

    // шукаємо транспорт з найбільшим об'ємом двигуна
    auto maxEngineVolume = max_element(transports.begin(), transports.end(), [](const Transport* a, const Transport* b) {
        return a->getEngineVolume() < b->getEngineVolume();
        });

    cout << "===============\n";
    cout << "LARGEST ENGINE:\n";
    cout << "===============\n\n";
    cout << **maxEngineVolume << endl;
    cout << "\n\n";

    // шукаємо транспорт з найменшим об'ємом двигуна
    auto minEngineVolume = min_element(transports.begin(), transports.end(), [](const Transport* a, const Transport* b) {
        return a->getEngineVolume() < b->getEngineVolume();
        });

    cout << "================\n";
    cout << "SMALLEST ENGINE:\n";
    cout << "================\n\n";
    cout << **minEngineVolume << endl;
    cout << "\n\n";

    // Виводимо тільки водний
    cout << "================\n";
    cout << "WATER TRANSPORT:\n";
    cout << "================\n\n";
    bool hasWaterTransport = false;
    for (const auto& transport : transports) {
        //перевіряємо чи транспорт не є амфібія
        if (dynamic_cast<AmphibianTransport*>(transport)) {
            continue;
        }

        // перевіряємо чи водний
        if (const auto* waterTransport = dynamic_cast<WaterTransport*>(transport)) {
            cout << *waterTransport << endl;
            hasWaterTransport = true;
        }
    }
    if (!hasWaterTransport) {
        cout << "    No water transport found!\n";
    }
    cout << "\n\n";

    // виводимо тільки амфібію
    cout << "====================\n";
    cout << "AMPHIBIAN TRANSPORT:\n";
    cout << "====================\n\n";
    bool hasAmphibianTransport = false;
    for (const auto& transport : transports) {
        // перевіряємо чи амфібія
        if (const auto* amphibianTransport = dynamic_cast<AmphibianTransport*>(transport)) {
            cout << *amphibianTransport << endl;
            hasAmphibianTransport = true;
        }
    }
    if (!hasAmphibianTransport) {
        cout << "    No amphibian transport found!\n";
    }

    return 0;
}


Transport* promptForTransportItem() {
    int choice;
    string name;
    int engineVolume;
    string typeOfWater;
    int maxSpeedInWater;
    int maxSpeedOnLand;
    int numberOfSeats;
    int maxHoursInWater;
    int maxHoursOnLand;

    cout << "    Choose the type of transport you want to add:\n\n";
    cout << "    1. Water transport\n";
    cout << "    2. Land transport\n";
    cout << "    3. Amphibian transport\n\n";
    cout << "    Your choice:\n    ==> ";
    cin >> choice;

    cout << "\n    Enter the name of the transport:\n    ==> ";
    cin >> name;

    cout << "\n    Enter the engine volume of the transport:\n    ==> ";
    cin >> engineVolume;

    switch (choice) {
    case 1:cout << "\n    Enter the type of water:\n    ==> ";
        cin >> typeOfWater;

        cout << "\n    Enter the max speed in water:\n    ==> ";
        cin >> maxSpeedInWater;

        return new WaterTransport(name, engineVolume, typeOfWater, maxSpeedInWater);
    case 2:cout << "\n    Enter the max speed on land:\n    ==> ";
        cin >> maxSpeedOnLand;

        cout << "\n    Enter the number of seats:\n    ==> ";
        cin >> numberOfSeats;

        return new LandTransport(name, engineVolume, maxSpeedOnLand, numberOfSeats);
    case 3:cout << "\n    Enter the type of water:\n    ==> ";
        cin >> typeOfWater;

        cout << "\n    Enter the max speed in water:\n    ==> ";
        cin >> maxSpeedInWater;

        cout << "\n    Enter the max speed on land:\n    ==> ";
        cin >> maxSpeedOnLand;

        cout << "\n    Enter the number of seats:\n    ==> ";
        cin >> numberOfSeats;

        cout << "\n    Enter the max hours in water:\n    ==> ";
        cin >> maxHoursInWater;

        cout << "\n    Enter the max hours on land:\n    ==> ";
        cin >> maxHoursOnLand;

        return new AmphibianTransport(
            name,
            engineVolume,
            typeOfWater,
            maxSpeedInWater,
            maxSpeedOnLand,
            numberOfSeats,
            maxHoursInWater,
            maxHoursOnLand
        );
    default:return nullptr;
    }
}