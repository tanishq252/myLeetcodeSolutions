class Solution {
public:
    int minOperations(vector<int>& nums) {
        int c = 0;
        int i=1;
        if(nums.size() == 1){return 0;}
        for(int i = 1;i<nums.size();i++ ){
            if(nums[i]<=nums[i-1]){
                c += (nums[i-1]-nums[i]+1);
                nums[i]+= (nums[i-1]-nums[i]+1);
            }
        }
        return c;
        
    }
};