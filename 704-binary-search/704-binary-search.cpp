class Solution {
public:
    int search(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        int mid = (high+low)/2;
        while(high>=low){
            if(nums[mid] == target){return mid;}
            else if(nums[mid] > target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
            mid = (high+low)/2;
        }
        return -1;
    }
};