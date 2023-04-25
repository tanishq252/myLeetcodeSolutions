class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    set<int> st;
    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) {pq.push(i);st.insert(i);}
    }
    
    int popSmallest() {
        int x = pq.top();
        pq.pop();
        st.erase(x);
        return x;
    }
    
    void addBack(int num) {
        if(st.find(num) == st.end()){
            st.insert(num);pq.push(num);
        }
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */