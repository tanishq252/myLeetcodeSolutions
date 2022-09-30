class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        map<int, vector<pair<int, int>>> mp;
        vector<vector<int>> ans;
        for(auto &i:buildings){
            mp[i[0]].push_back({i[2], 0}); //start point
            mp[i[1]].push_back({i[2], 1}); //end point
        }
        multiset<int> q;
        for(auto &[pos, heights]: mp){
            for(auto &[height, type]: heights){
                if(type == 0) q.insert(height); // if start point append height
                else q.erase(q.find(height)); // if end point erase the height since the range would be ended
            }
            int newHeight  = (q.empty()) ? 0 : *q.rbegin(); // if multiset is empty then all ranges have been covered 
            if(!ans.empty() and ans.back()[1] == newHeight) continue; //if the previous height is same as the current height then continue
            ans.push_back({pos, newHeight});
            // ans consists of the points where height changes 
        }
        return ans;
    }
};