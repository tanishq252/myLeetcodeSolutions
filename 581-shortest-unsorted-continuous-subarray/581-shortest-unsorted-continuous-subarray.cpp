class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(), v.end());
        if(nums == v||nums.size()==1){return 0;}
        vector<int> v1;
        int i=0;
        while(i<nums.size()){
            if(nums[i]!=v[i]){v1.push_back(i);}
            i++;
        }
        return 1+v1[v1.size()-1]-v1[0];
    }
};