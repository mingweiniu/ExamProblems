// 1603. Design Parking System

class ParkingSystem {
private:
    array<int,4> spaces;
public:
    ParkingSystem(int big, int medium, int small)
        :spaces({0, big, medium, small})
    {}    
    bool addCar(int carType) 
    {
        return 0 < spaces[carType]--;
    }
};