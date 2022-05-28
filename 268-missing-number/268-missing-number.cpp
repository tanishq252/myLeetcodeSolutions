class Solution {
public:
    //binary search recommended
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int low=0,high=nums.size()-1;
        while(high>=low){
            int mid = low+(high-low)/2;
            if(nums[mid] == mid){low = mid+1;}
            else{high = mid-1;}
        }
        return low;
    }
};