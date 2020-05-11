class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        Insert(x);
        s_.push(x);
    }
    
    void pop() {
        int x = s_.top();
        Delete(x);
        s_.pop();
    }
    
    int top() {
        return s_.top();
    }
    
    int getMin() {
        return list_.front();
    }
private:
    stack<int> s_;
    list<int> list_;

    void Insert(int val) {
        list<int>::iterator it = list_.begin();
        while (it != list_.end()) {
            if (*it > val) break;
            ++it;
        }
        list_.insert(it, val);
    }

    void Delete(int val) {
        list<int>::iterator it = list_.begin();
        while (it != list_.end()) {
            if (*it == val) {
                list_.erase(it);
                break;
            }
            ++it;
        }
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
