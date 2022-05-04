class ParkingSystem {
public:
    vector<int> v = {0,0,0};
    ParkingSystem(int big, int medium, int small) {
        v[0] = big;
        v[1] = medium;
        v[2] = small;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(v[0] == 0){
                return false;
            }
            v[0]--;
            return true;
        }
        else if(carType == 2){
            if(v[1] == 0){
                return false;
            }
            v[1]--;
            return true;
        }
        else if(carType == 3){
            if(v[2] == 0){
                return false;
            }
            v[2]--;
            return true;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */