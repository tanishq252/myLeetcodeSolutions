class KthLargest {
public:
    int j;
    vector<int> v;
    KthLargest(int k, vector<int>& nums) {
        j = k;
        v = nums;
        sort(v.begin(), v.end());
    }
    
    int add(int val) {
        v.insert(lower_bound(v.begin(), v.end(), val), val);
        return v[v.size()-j];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */