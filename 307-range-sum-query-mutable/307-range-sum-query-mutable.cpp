class NumArray {
public:
    vector<int> v;
    vector<int> BIT;
        
    void updateBIT(vector<int> &BIT, int val, int ind, int n){
        ind+=1;
        while(ind<=n){
            BIT[ind] += val;
            ind += ind & (-ind);
        }
    }
    
    int getSum(vector<int> &BIT, int ind){
        ind+=1;
        int s=0;
        while(ind>0){
            s+=BIT[ind];
            ind -= ind & (-ind);
        }
        return s;
    }
    
    NumArray(vector<int>& nums) {
        v = nums;
        BIT = vector<int>(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++){
            updateBIT(BIT, nums[i], i, nums.size());
        }
    }
    
    void update(int index, int val) {
        int diff = val - v[index];
        v[index] = val;
        updateBIT(BIT, diff, index, v.size());
    }
    
    int sumRange(int left, int right) {
        int s = getSum(BIT, right) - getSum(BIT, left-1);
        return s;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */