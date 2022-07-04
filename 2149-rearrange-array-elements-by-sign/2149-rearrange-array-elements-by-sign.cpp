class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        
        vector<int> vp;
        vector<int> vn;
        for(auto i:nums){
            if(i>0) {vp.push_back(i);}
            else {vn.push_back(i);}
        }
        
        int i=0;
        for(int j=0;j<vp.size();j++){
            nums[i++] = vp[j];
            nums[i++] = vn[j];
        }
        
        return nums;
        
        
        // passed 129/133 test cases
        
        // vector<int> vt;
        // int i=1;
        // if(nums[0]<0){
        //     while(i<nums.size()){
        //         if(nums[i] > 0){
        //             while(i > 0){
        //                 swap(nums[i], nums[i-1]);
        //                 i--;
        //             }
        //             break;
        //         }
        //         i++;
        //     }
        // }
        // i=0;
        // while(i<nums.size()-1){
        //     if((nums[i]>0 and nums[i+1]>0)){
        //         int j = i+2;
        //         while(j<nums.size()){
        //             if(nums[j]<0){
        //                 while(j!=i+1){
        //                     swap(nums[j], nums[j-1]);j--;
        //                 }
        //                 // swap(nums[i+1], nums[j]);
        //                 break;
        //             }
        //             j++;
        //         }
        //     }
        //     else if((nums[i]<0 and nums[i+1]<0)){
        //         int j = i+2;
        //         while(j<nums.size()){
        //             if(nums[j]>0){
        //                 while(j!=i+1){
        //                     swap(nums[j], nums[j-1]);j--;
        //                 }
        //                 // swap(nums[i+1], nums[j]);
        //                 break;
        //             }
        //             j++;
        //         }
        //     }
        //     i++;
        // }
        // return nums;
    }
};