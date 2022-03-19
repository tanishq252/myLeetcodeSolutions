class FreqStack {
public:
    map<int, int> freq;
    map<int, stack<int>> grp_stack;
    int maxFreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        grp_stack[freq[val]].push(val);
    }
    
    int pop() {
        
        int top_maxFreq = grp_stack[maxFreq].top();
        freq[top_maxFreq]--;
        grp_stack[maxFreq].pop();
        if(grp_stack[maxFreq].size() == 0){
            maxFreq--;
        }
        return top_maxFreq;
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */