// https://leetcode.com/problems/number-of-good-paths/description/

class Solution {
public:

    // 123/134 test cases passed
    int ans = 0;
    set<pair<int, int>> st;
    void dfs(int node, vector<int>& vals, vector<vector<int>>& adjL, vector<bool> &visited, int parent){
        if(visited[node]) return;
        visited[node]=true;
        if(node != parent){
                if(vals[node]==vals[parent] and st.find({node, parent})==st.end()) {
                    ans++;
                    st.insert({node, parent});
                    st.insert({parent, node});
                }
        }
        for(auto &i:adjL[node]){
            if(!visited[i]){
                if(vals[parent] >= vals[i]){
                    dfs(i, vals, adjL, visited, parent);
                }
            }
        }
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adjL(n);
        vector<bool> visited(n);
        for(auto &i:edges){
            adjL[i[0]].push_back(i[1]);
            adjL[i[1]].push_back(i[0]);
        }
        for(int i=0;i<n;i++){
            dfs(i, vals, adjL, visited, i);
            visited = vector<bool> (n);
        }
        cout<<ans;
        return ans+n;
    }
};