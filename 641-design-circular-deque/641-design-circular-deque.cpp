class MyCircularDeque {
public:
    int size;
    vector<int> v;
    
    MyCircularDeque(int k) {
        size = k;
    }
    
    bool insertFront(int value) {
        if(isFull()) return false;
        v.resize(v.size()+1);
        for(int i=v.size()-1;i>=1;i--) v[i] = v[i-1];
        v[0] = value;
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull()) return false;
        v.push_back(value);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty()) return false;
        vector<int> vd(v.begin()+1, v.end());
        v = vd;
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty()) return false;
        
        v.pop_back();
        return true;
    }
    
    int getFront() {
        return isEmpty() ? -1 : v[0];
    }
    
    int getRear() {
        for(auto i:v) cout<<i<<" ";
        return isEmpty() ? -1 : v[v.size()-1];
    }
    
    bool isEmpty() {
        if(v.size() == 0) return true;
        return false;
    }
    
    bool isFull() {
        if(v.size() == size) return true;
        return false;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */