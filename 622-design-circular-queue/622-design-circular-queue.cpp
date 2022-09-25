class MyCircularQueue {
public:
    int size, ind;
    vector<int> v;
    MyCircularQueue(int k) {
        size = k;
    }
    
    bool enQueue(int value) {
        if(!isFull()){
            v.push_back(value);
            return true;
        }
        return false;
    }
    
    bool deQueue() {
        if(!isEmpty()){
            vector<int> vd(v.begin()+1, v.end());
            v = vd;
            return true;
        }
        return false;
    }
    
    int Front() {
        if(isEmpty()) return -1;
        return v[0];
    }
    
    int Rear() {
        if(isEmpty()) return -1;
        return v[v.size()-1];
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
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */