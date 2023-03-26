#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#include <iostream>
#include <string>

using namespace std;

class Transport {
protected:


    int engineCapacity;
    string name;

public:
    Transport(int engineCapacity, const string& name) {}
    int getEngineCapacity() const {


        return engineCapacity;
    }
    const string& getName() const {


        return name;
    }
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Engine capacity: " << engineCapacity;
    }
};

class WaterVehicle : virtual public Transport {
protected:
    string waterType;
    int maxSpeed;
public:
    WaterVehicle(int engineCapacity, const string& name, const string& waterType, int maxSpeed)
    Transport(engineCapacity, name), waterType(waterType), maxSpeed(maxSpeed) {}

    const string& getWaterType() const {
        return waterType;
        int getMaxSpeed() const {


            return maxSpeed;
        }
    }

    displayInfo();
    cout << "Water type: " << waterType << " Max speed in water: " << maxSpeed;
}
};
class LandVehicle : virtual public Transport {
protected:


    int maxSpeed;


    int numberOfSeats;

public:
    LandVehicle(int engineCapacity, const string& name, int maxSpeed, int numberOfSeats)

        Transport(engineCapacity, name), maxSpeed(maxSpeed), numberOfSeats(numberOfSeats) {}
    int getMaxSpeed() const {


        return maxSpeed;
    }





    class Amphibian : public WaterVehicle, public LandVehicle {


        int maxTimeInWater;


        int maxTimeInAir;
    };