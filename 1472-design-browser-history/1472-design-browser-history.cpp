class DLL {
public:
    string data;
    DLL *prev, *next;

    DLL(string url) {
        data = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory {
public:
    
    DLL* head;
    DLL* current;
    BrowserHistory(string homepage) {
        
        head = new DLL(homepage);
        current = head;
    }
    
    void visit(string url) {
        
        DLL* newNode = new DLL(url);
        current->next = newNode;
        newNode->prev = current;
        current = newNode;        
    }
    
    string back(int steps) {
        
        while(steps > 0 && current->prev)
        {
            current = current->prev;
            steps--;
        }
        
        return current->data;
    }
    
    string forward(int steps) {
        
        while(steps > 0 && current->next)
        {
            steps--;
            current = current->next;
        }
        
        return current->data;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */