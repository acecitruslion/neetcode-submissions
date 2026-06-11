class MyQueue {
public:
    stack<int> s,t;
    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(t.empty()) {
            while(!s.empty()) {
                int num = s.top();
                s.pop();
                t.push(num);
            }
        }
        int res = t.top();
        t.pop();
        return res;
    }
    
    int peek() {
        if(t.empty()) {
            while(!s.empty()) {
                int num = s.top();
                s.pop();
                t.push(num);
            }
        }
        int res = t.top();
        return res;
    }
    
    bool empty() {
        return (s.empty() && t.empty());
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