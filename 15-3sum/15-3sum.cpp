class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        set<vector<int>> s;
        if(nums.size()<3){
            return ans;
        }
        sort(nums.begin(), nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(i> 0){
                while(i<nums.size() and nums[i]==nums[i-1])
                    i++;
            }
            
            int j=i+1;
            int k = nums.size()-1;
            while(j<k){
                    int f = nums[i]+nums[j]+nums[k];
                    if(f==0){
                        if(i!=j && i!=k)
                            {vector<int> v = {nums[i], nums[j], nums[k]};
                            s.insert(v);
                            }
                        j++; 
                        k--;
                    }else if(f<0){
                        j++;
                    }else if(f>0){
                        k--;
                    }
                if(j==nums.size() || k==0){
                    break;
                }
            }
        }
        for(auto i:s){
            ans.push_back(i);
        }
        return ans;
    }
};