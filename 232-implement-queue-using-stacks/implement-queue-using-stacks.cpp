class MyQueue {
public:
    stack<int>input;
    stack<int>output;
    int peekElem=-1;
    MyQueue() {
        
    }
    void push(int x) {
        if(input.empty())
        {
            peekElem=x;
        }
        input.push(x);
    }
    
    int pop() {
        int top=-1;
        if(empty())
        {
            return -1;
        }
        if(!output.empty())
        {
           top=output.top();
           output.pop();
            return top;
        }
        else
        {
            while(!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        top=output.top();
        output.pop();
        return top;
    }
    
    int peek() {
        if(!output.empty())
        {
            return output.top();
        }
        return peekElem;
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