class Solution {
public:
    void dfs(int i,int d, vector<bool> &v, vector<vector<int>> &adjL, vector<int> &m){
        if(adjL[i].size() == 0 or v[i]==true) return;
        v[i]=true;
        for(auto &j:adjL[i]){
            m[j]=(m[j]==-1)?d:m[j];
            dfs(j, d+1,v, adjL, m);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        if(node1==node2) return node1;
        vector<int> mp(n),mp1(n);
        for(int i=0;i<n;i++) {mp[i]=-1;mp1[i]=-1;}
        vector<vector<int>> adjL(n);
        for(int i=0;i<n;i++){
            if(edges[i]!=-1) adjL[i].push_back(edges[i]);
        }
        vector<bool> visited(n);
        dfs(node1,1, visited, adjL, mp);
        visited=vector<bool> (n);
        dfs(node2,1, visited, adjL, mp1);
        int ans = INT_MAX, mn=INT_MAX;
        if(mp[node2]>0 ){
            if(mn>mp[node2]){
                mn = mp[node2];
                ans = node2;
            }else if(mn == mp[node2]){
                ans = min(ans, node2);
            }
        }
        if(mp1[node1]>0){
            if(mn>mp1[node1]){
                mn = mp1[node1];
                ans = node1;
            }else if(mn == mp1[node1]){
                ans = min(ans, node1);
            }
        }

        for(int i=0;i<n;i++){
            if(mp[i]>0 and mp1[i]>0){
                mp[i] = max(mp[i], mp1[i]);
                if(mp[i]<mn){
                    mn = mp[i];
                    ans = i;
                }else if(mn == mp[i]){
                    ans = min(ans, i);
                }
            }else{
                mp[i]=-1;
            }
        }

        return (ans == INT_MAX) ? -1:ans;
    }
};