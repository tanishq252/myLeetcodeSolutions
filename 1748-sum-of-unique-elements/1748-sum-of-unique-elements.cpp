class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int c=1;
        sort(nums.begin(), nums.end());
        vector<int> v;
        v.push_back(0);
        if(nums.size() == 1){return nums[0];}
        for(int i=1;i<nums.size()-1;i++){
            if(nums[i]==nums[i-1]||nums[i]==nums[i+1]){continue;}
            else{v.push_back(nums[i]);}
        }
        
        if(nums[nums.size()-1]!=nums[nums.size()-2]){v.push_back(nums[nums.size()-1]);}
        if(nums[1]!=nums[0]){v.push_back(nums[0]);}
        int s=0;
        for(int i=0;i<v.size();i++){
           s+=v[i] ;
        }
        return s;
    }
};