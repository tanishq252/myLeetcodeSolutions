class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(n, 0);
        vector<int> ans(2,0);
        for(auto &i:nums){
            v[i-1]++;
        }
        bool f1=false, f2=false;
        for(int i=0;i<v.size();i++){
            if(v[i]==0){
                ans[1]=i+1;f1=true;
            }else if(v[i]==2){
                ans[0]=i+1;f2=true;
            }
            
            if(f1 and f2) return ans;
        }
        return ans;
    }
};