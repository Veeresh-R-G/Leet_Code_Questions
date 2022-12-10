class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        /*
            360 / 12 = 30 degrees 
            
            
            so when minute hand covers 
            360 --> hour hand covers 30
            180 --> hour hand covers 15
            1 deg --> hour hand covers 30/360 ==> 1/12 degrees
            
            5 mins == 30 deg
            1 min == 6 deg
            
            
            
            
        */
        
        float minAngle = minutes * 6;
        float hourAngle =  hour != 12 ? minAngle / 12 + ((hour * 360 / 12) ) : minAngle / 12;
        
        return abs(minAngle - hourAngle) > 360 - abs(minAngle - hourAngle) ? 
            360 - abs(minAngle - hourAngle) : abs(minAngle - hourAngle);
    }
};