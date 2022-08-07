class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0,j,k;
        if(nums.size()==3){
            if(nums[0]+nums[1]+nums[2] == 0){
                return {{nums[0], nums[1], nums[2]}};
            }else{
                return {};
            }
        }
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        int n = nums.size();
        while(i<n-2){
            j = i+1;
            k = n-1;
            while(j<k){
                int s = nums[i]+nums[j]+nums[k];
                if(s==0){
                    st.insert({nums[i], nums[j], nums[k]});
                    j++;k--;
                }else if(s>0){
                    k--;
                }else{
                    j++;
                }
            }
            i++;
        }
        return vector<vector<int>> (st.begin(), st.end());
    }
};