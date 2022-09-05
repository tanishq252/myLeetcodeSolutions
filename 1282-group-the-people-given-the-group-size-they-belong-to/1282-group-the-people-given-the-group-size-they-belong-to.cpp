class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        vector<vector<int>> ans;
        for(int i=0;i<groupSizes.size();i++){
            mp[groupSizes[i]].push_back(i);
        }
        for(auto i:mp){
            for(int j=0;j<i.second.size();j++){
                vector<int> v(i.second.begin()+j, i.second.begin()+j+i.first);
                ans.push_back(v);
                j+=(i.first-1);
            }
        }
        return ans;
        
    }
};      