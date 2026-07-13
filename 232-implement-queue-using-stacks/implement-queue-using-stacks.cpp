class MyQueue {
public:
    stack<int>insert,remove;
    int peekElem=-1;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(insert.empty())
        {
            peekElem=x;
        }
        insert.push(x);
    }
    
    int pop() {
        if(empty())
        {
            return -1;
        }
        if(remove.empty())
        {
            while(!insert.empty())
            {
                remove.push(insert.top());
                insert.pop();
            }
        }
        int top=remove.top();
        remove.pop();
        return top;
    }
    
    int peek() {
        if(remove.empty())
        {
        return peekElem;
        }
        return remove.top();
    }
    
    bool empty() {
        return insert.empty() && remove.empty();
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