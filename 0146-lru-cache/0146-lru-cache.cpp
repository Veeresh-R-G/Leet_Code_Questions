class LRUCache {
public:
    
    class node
    {
        public: 
        int key;
        int val;
        node* next;
        node* prev;
        
        node(int _key , int _val){
            key = _key;
            val = _val;
        }
    };
    
    node* head = new node(-1 , -1);
    node* tail = new node(-1 , -1);
    
    int cap;
    unordered_map<int , node*> myMap;
    
    
    LRUCache(int capacity) {
        
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        
        if(myMap.find(key) != myMap.end())
        {
            
            auto Node = myMap[key];
            int value = Node->val;
            
            //Deleting Old Value form Map
            myMap.erase(Node->key);
            
            
            //Have to update the Node as most recently used block
            Node->next->prev = Node->prev;
            Node->prev->next = Node->next;
            Node->prev = NULL;
            Node->next = NULL;
            delete Node;
            
            auto newNode = new node(key , value);
            
            newNode->next = head->next;
            head->next = newNode;
            newNode->next->prev = newNode;
            newNode->prev = head;
            
            //Update in the Map with the new address
            myMap[key] = newNode;
            
            return value;
        }
        
        return -1;
    }
    
    void put(int key, int value) {
        
        if(myMap.find(key) != myMap.end())
        {
            //if its already there
            auto Node = myMap[key];
            
            //Deleting Stale Copy
            myMap.erase(key);
            
            Node->next->prev = Node->prev;
            Node->prev->next = Node->next;
            Node->prev = NULL;
            Node->next = NULL;
            delete Node;
            
            
            //Adding the new Updated Node(new address)
            auto newNode = new node(key , value);            
            
            newNode->next = head->next;
            head->next = newNode;
            newNode->next->prev = newNode;
            newNode->prev = head;
            
            //Update in the Map with the new address
            myMap[key] = newNode;
        }
        else
        {
            
            //If its not there
            if(myMap.size() == cap)
            {   
                
                //Implementation of LRU concept
              
                
                //Deleting the Least Frequently Used Block
                //That is from the Tail End
                auto Node = tail->prev;
                auto KEY = Node->key;
                myMap.erase(KEY);
                
                
                tail->prev = Node->prev;
                Node->prev->next = tail;
                Node-> prev = NULL;
                Node-> next = NULL;
                delete Node;
                
                //Creating the New node With the specified Key and Value
                auto newNode = new node(key , value);
                newNode->next = head->next;
                head->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev = head;
                
                myMap[key] = newNode;
                
            }
            else
            {
                auto newNode = new node(key , value);
                
                //Most recently Used Block
                newNode->next = head->next;
                head->next = newNode;
                newNode->next->prev = newNode;
                newNode->prev = head;

                //Update in the Map with the new address
                myMap[key] = newNode;
            }
        }
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */