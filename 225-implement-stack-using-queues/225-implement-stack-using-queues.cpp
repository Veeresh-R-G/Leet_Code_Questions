class MyStack {
public:
    
    /*
        
        1. Using 2 Queues
        
        q1      q2
        
        Push in q2
        transfer all elements of q1 to q2 element by element
        
        then swap q1 <--> q2
        
        the reason we are using the second queue is two store the incoming element
        
        and get it at the front of the queue to mimic the FILO property of the stack
        
        
        2. Using 1 Queue
        
        q1
        
        push into q1
        
        if q1 is not empty
        
        calculate size of q1 
        
        for size - 1 times take the element from front and push it back
        
    */
    
    queue<int> q1;
    queue<int> q2;
    
    queue<int> q3;
    MyStack() {
        
    }
    
    void push(int x) {
        
        q3.push(x);
        
        int n = q3.size();
        
        while(n > 1)
        {
            int front = q3.front();
            q3.pop();
            
            q3.push(front);
            n--;
        }
        /*
        
            ------------------IMPLEMENTATION - 1----------------------------------
                                   2 QUEUES
            
        q2.push(x);
        
        while(!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            
            q2.push(temp);
        }
        
        swap(q1 , q2);
    
       */
    }
    int pop() {
        
         int temp  = q3.front();
        
        q3.pop();
        
        return temp;
        
        /*
        ------------------IMPLEMENTATION - 1----------------------------------
                                   2 QUEUES
        int temp  = q1.front();
        
        q1.pop();
        
        return temp;
        
        */    
    }
    
    int top() {
        return q3.front();
    }
    
    bool empty() {
        
        return q3.empty() == true ? true : false;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */