class MyStack {
public:
    queue<int> p,q;
    MyStack() {

    }
    
    void push(int x) {
        if(!p.empty()) {
            p.push(x);
        }
        else {
            q.push(x);
        }
    }
    
    int pop() {
        if(!p.empty()) {
            int n = p.size();
            for(int i=0;i<n-1;i++) {
                int num = p.front();
                p.pop();
                q.push(num);
            }
            int res = p.front();
            p.pop();
            return res;
        }
        else {
            int n = q.size();
            for(int i=0;i<n-1;i++) {
                int num = q.front();
                q.pop();
                p.push(num);
            }
            int res = q.front();
            q.pop();
            return res;
        }
    }
    
    int top() {
        if(!p.empty()) {
            int n = p.size();
            for(int i=0;i<n-1;i++) {
                int num = p.front();
                p.pop();
                p.push(num);
            }
            int num = p.front();
            p.pop();
            p.push(num);
            return num;
        }
        else {
            int n = q.size();
            for(int i=0;i<n-1;i++) {
                int num = q.front();
                q.pop();
                q.push(num);
            }
            int num = q.front();
            q.pop();
            q.push(num);
            return num;
        }
    }
    
    bool empty() {
        return (p.empty() && q.empty());
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