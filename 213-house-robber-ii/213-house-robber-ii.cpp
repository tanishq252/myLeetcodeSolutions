class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1){
            return nums[0];
        }
        int odd = 0, even = 0;
        // if(nums[0]>nums[nums.size()-1]){
        //     for(int i=0;i<nums.size()-1;i++){
        //         if(i%2==0){
        //             even+=nums[i];
        //             even = max(even, odd);
        //         }else{
        //             odd+=nums[i];
        //             odd = max(even, odd);
        //         }
        //     }
        // }
        // else if(nums[0]==nums[nums.size()-1]){
            for(int i=0;i<nums.size()-1;i++){
                if(i%2==0){
                    even+=nums[i];
                    even = max(even, odd);
                }else{
                    odd+=nums[i];
                    odd = max(even, odd);
                }
            }
            int mx = max(even, odd);
            even =0;
            odd=0;
            for(int i=1;i<nums.size();i++){
                if(i%2==0){
                    even+=nums[i];
                    even = max(even, odd);
                }else{
                    odd+=nums[i];
                    odd = max(even, odd);
                }
            }
            int mx1 = max(even, odd);
            return max(mx, mx1);
        // }
        // else{
        //     for(int i=1;i<nums.size();i++){
        //         if(i%2==0){
        //             even+=nums[i];
        //             even = max(even, odd);
        //         }else{
        //             odd+=nums[i];
        //             odd = max(even, odd);
        //         }
        //     }
        // }
        // return max(even, odd);
    }
};