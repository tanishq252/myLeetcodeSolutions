class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long currentLength = 0;
        int i=0;
        while(i< nums.size()){
            if(nums[i] == 0){
               while(nums[i]==0 and i<nums.size()) {
                   currentLength++;
                   i++;
                   if(i==nums.size()){
                       break;
                   }
               }
                cout<<currentLength<<" ";
               ans += ((currentLength*(currentLength+1))/2);
            }
            currentLength = 0;
            i++;
        }
        
        return ans;
    }
};