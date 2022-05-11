class Solution {
public:
    int rob(vector<int>& nums) {
        int odd=0, even=0;
        for(int i=0;i<nums.size();i++){
            if(i%2!=0) {
                odd+=nums[i]; 
                odd = odd>even?odd:even;
            } else{
                even+=nums[i]; 
                even = odd>even?odd:even;
            }        
        }
        return (odd>even)?odd:even;
    }
};