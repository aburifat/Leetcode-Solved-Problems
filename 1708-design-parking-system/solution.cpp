class ParkingSystem {
    vector<int>v;
public:
    ParkingSystem(int big, int medium, int small) {
        v={big,medium,small};
    }
    
    bool addCar(int carType) {
        return v[carType-1]?v[carType-1]--:0;
    }
};
