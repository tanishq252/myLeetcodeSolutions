class Solution {
public:
    int minDeletion(vector<int>& nums) {
        
        int deleted = 0;
        int n = nums.size();
        set<int> s(nums.begin(), nums.end());
        if(s.size()==1){return nums.size();}
        if(n==1){return 1;}
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]==nums[i+1] && (i-deleted)%2==0){
                deleted++;
            }
        }
        return deleted + (nums.size()-deleted)%2;
        
        
//          Passed 107/114 test cases   
        
//         int n = nums.size();
//         set<int> s(nums.begin(), nums.end());
//         if(s.size()==1){return nums.size();}
//         if(n==1){return 1;}
//         for(int i=0;i<nums.size();i+=2){
//             while(nums[i]==nums[i+1] && i<nums.size()){
//                 nums.erase(nums.begin()+i);
//                 // i-=2;
//             }
//         }
        
//         if(nums.size()%2==1){
//             return n-nums.size()+1;
//         }
//         return n-nums.size();
    }
};