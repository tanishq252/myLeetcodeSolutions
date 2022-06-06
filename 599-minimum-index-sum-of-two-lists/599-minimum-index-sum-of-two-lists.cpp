class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string, int> mp;
        vector<string> ans;
        int mn = INT_MAX;
        for(int i=0;i<list1.size();i++){
            mp[list1[i]] = i;
            // mn = min(mn, i);
        }
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                if(mp[list2[i]]+i < mn){
                ans = {};
                ans.push_back(list2[i]);
                mn = min(mn, mp[list2[i]]+i);
            }else if(mp[list2[i]]+i == mn){
                ans.push_back(list2[i]);
            }
            }
        }
        return ans;
    }
};