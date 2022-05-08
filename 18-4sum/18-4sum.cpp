class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        if(n<4){return ans;}
        for(int i=0;i<nums.size();i++){
            // if(i>0){
                // while(i<n && nums[i]==nums[i-1])
            //         i++;
            // }
            for(int j=i+1;j<n-2;j++){
                int k = j+1;
                int l = n-1;
                while(k<l){
                    // if(target<nums[i]||target<nums[j]||target<nums[k]||target<nums[l]){
                    //     break;
                    // }
                    int s = ((nums[i]%1000000007+nums[j]%1000000007)%1000000007+(nums[k]%1000000007+nums[l]%1000000007)%1000000007)%1000000007;
                    if(s==target){
                        vector<int> v = {nums[i], nums[j], nums[k], nums[l]};
                            st.insert(v);
                        k++;
                        l--;
                    }
                    else if(s<target){
                        k++;
                    }
                    else if(s>target){
                        l--;
                    }
                }
            }
        }
        for(auto i:st){
            ans.push_back(i);
        }
        return ans;
    }
};