class MinStack {
public:
    vector<int> elements;
    int mn;
    
    MinStack() {
        
    }
    
    void push(int val) {
        elements.push_back(val);
        mn = *min_element(elements.begin(), elements.end());
    }
    
    void pop() {
        elements.pop_back();
        mn = *min_element(elements.begin(), elements.end());
    }
    
    int top() {
        return elements.back();
    }
    
    int getMin() {
        return mn;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */