class MyQueue {
public:
    stack<int> st;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        stack<int> temp = st;
        stack<int> s;
        while(!st.empty()){
            int x = st.top();
            s.push(x);
            st.pop();
        }
        int x = s.top();
        s.pop();
        while(!s.empty()){
            int i = s.top();
            st.push(i);
            s.pop();
        }
        return x;
    }
    
    int peek() {
        stack<int> temp = st;
        stack<int> s;
        while(!st.empty()){
            int x = st.top();
            s.push(x);
            st.pop();
        }
        int x = s.top();
        // s.pop();
        while(!s.empty()){
            int i = s.top();
            st.push(i);
            s.pop();
        }
        return x;
    }
    
    bool empty() {
        return (st.empty()) ?  true:false;
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