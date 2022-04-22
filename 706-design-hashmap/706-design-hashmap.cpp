class MyHashMap {
public:
    
    unordered_map<int , int> myMap;
    
    MyHashMap() {
        
    }
    
    void put(int key, int value) {
        if(myMap.find(key) == myMap.end()){
            //not there
            //so add in map
            myMap[key] = value;
            //myMap.insert(pair<int , int>(key , value));
        }
        else{
            myMap[key] = value;
        }
    }
    
    int get(int key) {
        // unordered_ map<int, int>::iterator itr;
        
        if(this->myMap.find(key) != this->myMap.end()){
            return this->myMap[key];
        }
        else{
            return -1;
        }
    }
    
    void remove(int key) {
        myMap.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */