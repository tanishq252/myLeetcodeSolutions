class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        v = nums;
    }
    
    int sumRange(int left, int right) {
        return accumulate(v.begin()+left,v.begin()+right+1,0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */