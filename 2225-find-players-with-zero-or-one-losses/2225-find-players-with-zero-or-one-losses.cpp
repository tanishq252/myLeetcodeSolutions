class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans = {{}, {}};
        map<int, int> winners;
        map<int, int> losers;
        set<int> st;
        for(auto i:matches){
            winners[i[0]]++;
            losers[i[1]]++;
            st.insert(i[0]);            
            st.insert(i[1]);
        }
        for(auto i:st){
            if(losers.find(i) == losers.end()){
                ans[0].push_back(i);
            }else if(losers[i] == 1){
                ans[1].push_back(i);
            }
        }
        return ans;
        
    }
};