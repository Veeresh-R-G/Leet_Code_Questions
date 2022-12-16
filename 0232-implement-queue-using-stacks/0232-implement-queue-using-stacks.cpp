class MyQueue {
public:
    stack<int> input , output;
    MyQueue() {
        
        
    }
    
    void push(int x) {
        this->input.push(x);
    }
    
    int pop() {
        
        if(!output.empty())
        {
            int top = output.top();
            output.pop();
            return top;
        }
        
        while(!input.empty())
        {
            int top = input.top();
            input.pop();
            
            output.push(top);
            
        }
        
        int top = output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        if(!output.empty())
        {
            return output.top();
        }
        
        while(!input.empty())
        {
            int top = input.top();
            input.pop();
            
            output.push(top);
            
        }
        
        int top = output.top();
        return top;
    }
    
    bool empty() {
        
        return input.empty() && output.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */