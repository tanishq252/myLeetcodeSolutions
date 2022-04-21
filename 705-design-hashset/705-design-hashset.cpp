class MyHashSet {
public:
    set<int> newSet;
    MyHashSet() {
        
    }
    
    void add(int key) {
        newSet.insert(key);
    }
    
    void remove(int key) {
        newSet.erase(key);
    }
    
    bool contains(int key) {
        return newSet.count(key)==1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */