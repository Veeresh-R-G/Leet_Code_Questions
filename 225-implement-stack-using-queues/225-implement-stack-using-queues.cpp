class MyStack {
public:
    
    /*
        First Implementation : 
        
        1. Using 2 Queues
        
        q1      q2
        
        Push in q2
        transfer all elements of q1 to q2 element by element
        
        then swap q1 <--> q2
        
        the reason we are using the second queue is two store the incoming element
        
        and get it at the front of the queue to mimic the FILO property of the stack
    */
    
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q2.push(x);
        
        while(!q1.empty())
        {
            int temp = q1.front();
            q1.pop();
            
            q2.push(temp);
        }
        
        swap(q1 , q2);
    }
    
    int pop() {
        
        int temp  = q1.front();
        
        q1.pop();
        
        return temp;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        
        return q1.empty() == true ? true : false;
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