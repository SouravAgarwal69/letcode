class MyQueue {
public:
  stack<int>pushed;
  stack<int>poped;
  int top=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        pushed.push(x);
    }
    
    int pop() {
        if(poped.empty())
        {
            while(!pushed.empty())
            {
                poped.push(pushed.top());
                pushed.pop();
            }
        }
        int x=poped.top();
        poped.pop();
        return x;
    }
    
    int peek() {
        if(poped.empty())
        {
            while(!pushed.empty())
            {
                poped.push(pushed.top());
                pushed.pop();
            }
        }
        return poped.top();
    }
    
    bool empty() {
        return pushed.empty() && poped.empty();
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