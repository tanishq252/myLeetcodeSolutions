class Solution {
public:
    
    int ans=INT_MAX;
    
    int changes(string s, string ss){
        int change=0;
        for(int i=0;i<s.length();i++){
            if(s[i]!=ss[i]) change++;
        }
        return change;
    }
    
    void bfs(int i, string &start, string &end, vector<vector<int>> &g, vector<bool> &visited, int count, vector<string> &bank){
        visited[i]=true;
        count++;
        for(int j=0;j<g[i].size();j++){
            if(bank[g[i][j]] == end) {
                cout<<count<<" ";
                ans = min(ans, count);
                return;
            }
            if(visited[g[i][j]] == false){
                cout<<bank[g[i][j]]<<" ";
                bfs(g[i][j], start, end, g, visited, count, bank);visited[g[i][j]]=false;
            } 
        }
        visited[i]=false;
        count--;
        cout<<"\n";
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        if(count(bank.begin(), bank.end(), end)<1) return -1;
        int c=0;
        vector<vector<int>> g;
        set<string> st(bank.begin(), bank.end());
        bank = vector<string>(st.begin(), st.end());
        cout<<bank.size();
        vector<bool> visited(bank.size(), false);
        for(int i=0;i<bank.size();i++){
            g.push_back({});
            for(int j=0;j<bank.size();j++){
                if(changes(bank[i], bank[j]) == 1){
                    g[i].push_back(j);
                }
            }
        }

        for(int i=0;i<bank.size();i++){
            if(changes(start, bank[i]) == 1){
                cout<<bank[i]<<" ";
                if(end == bank[i]) return 1;
                else {
                    bfs(i, start, end, g, visited, 1, bank);
                    visited = vector<bool> (bank.size());
                }
            }
        }
        cout<<"\nANS: "<<ans;
        return ans==INT_MAX ? -1:ans;
    }
};