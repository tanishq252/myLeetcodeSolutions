class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0,j=0, n=nums.size();
        vector<int> v;
        map<int, int> mp;
        while(i<n){
            if(mp[nums[i]]==2){
                i++;
            }else{
                mp[nums[i]]++;
                nums[j++] = nums[i++];
            }
        }
        
        return j;
    }
};