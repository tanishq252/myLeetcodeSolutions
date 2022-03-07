class Solution {
public:
    int find(vector<int>& nums, int original){
        for(int i=0;i<nums.size();i++){
            if(original == nums[i]){
                return find(nums,original*2);
            }
        }
        return original;
    }
    
//     recursion solution passed all the test cases
    
    int findFinalValue(vector<int>& nums, int original) {
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size();i++){
            if(original == nums[i]){
                original*=2;
            }
        }
        return original;
    }
};