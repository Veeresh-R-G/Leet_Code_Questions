class MyHashSet {
    int arr[10005];
    int st = 0;
public:
    
    MyHashSet() {
        for(int i = 0 ; i < 10005 ; i++){
            arr[i] = -1;
        }
    }
    
    void add(int key) {
        arr[st++] = key;
    }
    
    void remove(int key) {
        int index = st;
        while(index >= 0){
            if(arr[index] == key){
                arr[index] = -1; // element removed
            }
            index--;
        }
        
    }
    
    bool contains(int key) {
        for(int i = 0 ; i < st ; i++){
            if(arr[i] == key){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */