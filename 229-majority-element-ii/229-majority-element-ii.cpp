class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        map<int, int> mp;
        vector<int> v;
        set<int> st;
        for(auto &i:nums){
            mp[i]++;
            if(mp[i] > nums.size()/3 and st.find(i)==st.end()){
                v.push_back(i);
                st.insert(i);
            }
        }
        return v;
    }
};