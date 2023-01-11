// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/

class Solution {
public:
    unordered_map<int, int> mp;

    int dfs(int c, vector<vector<int>> &adjL, vector<bool> &visited, vector<bool> &hasApple){
        if(visited[c]) return 0;
        visited[c]=true;
        int ans=0;
        for(auto &i:adjL[c]){
            int k;
            if(!visited[i]){
                k=dfs(i,adjL,visited,hasApple);
                if(hasApple[i]) mp[c]+=2;
                if(k>0){
                    if(!hasApple[i]) mp[c]+=(k+2);
                    else mp[c]+=k;
                }
            }
        }
        return mp[c];
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adjL(n);
        vector<bool> visited(n);
        for(int i=0;i<n;i++) mp[i]=0;
        for(auto &i:edges){
            adjL[i[0]].push_back(i[1]);
            adjL[i[1]].push_back(i[0]);
        }
        int ans = dfs(0,adjL,visited,hasApple);
        return ans;
    }
};