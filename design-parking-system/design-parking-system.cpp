class ParkingSystem {

private:
    int big , md , sm;

    //big --> 1
    //md --> 2
    //sma --> 3
public:
    ParkingSystem(int big, int medium, int small) {
        
        this->big = big;
        md = medium;
        sm = small;
    }
    
    bool addCar(int carType) {
        
        if(carType == 1)
        {
            if(big > 0)
            {
                big--;
                return true;
            }
        }

        if(carType == 2)
        {
            if(md > 0)
            {
                md--;
                return true;
            }
        }

        if(carType == 3)
        {
            if(sm > 0)
            {
                sm--;
                return true;
            }
        }


        
        return false;
    
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */