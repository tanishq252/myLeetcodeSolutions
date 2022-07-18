class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        vector<int> v;
        set<pair<int, int>> st;
        int c=0;

        for(int i=0;i<nums.size();i++){
            v.push_back(nums[i]);
        }
        
        sort(v.begin(), v.end(), [](int a, int b){
            return a > b;
        });

        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(v[i]-v[j] == k){
                   st.insert({v[i], v[j]});
                }
            }
        }
        
        return st.size();
    }
};