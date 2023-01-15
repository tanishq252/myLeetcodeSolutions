class UnionFind {
private:
    vector<int> parent, rank;

public:
    UnionFind(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; i++) {
            parent[i] = i;
        }
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    void union_set(int x, int y) {
        int xset = find(x), yset = find(y);
        if (xset == yset) {
            return;
        } else if (rank[xset] < rank[yset]) {
            parent[xset] = yset;
        } else if (rank[xset] > rank[yset]) {
            parent[yset] = xset;
        } else {
            parent[yset] = xset;
            rank[xset]++;
        }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        // Mapping from value to all the nodes having the same value in non-descending order of values.
        map<int, vector<int>> valuesToNodes;
        for (int node = 0; node < n; node++) {
            valuesToNodes[vals[node]].push_back(node);
        }

        UnionFind dsu(n);
        int goodPaths = 0;

        // Iterate over all the nodes with the same value in sorted order, starting from the lowest
        // value.
        for (auto& [value, nodes] : valuesToNodes) {
            // For every node in nodes, combine the sets of the node and its neighbors into one set.
            for (int node : nodes) {
                for (int neighbor : adj[node]) {
                    // Only choose neighbors with a smaller value, as there is no point in
                    // traversing to other neighbors.
                    if (vals[node] >= vals[neighbor]) {
                        dsu.union_set(node, neighbor);
                    }
                }
            }
            // Map to compute the number of nodes under observation (with the same values) in each
            // of the sets.
            unordered_map<int, int> group;
            // Iterate over all the nodes. Get the set of each node and increase the count of the
            // set by 1.
            for (int u : nodes) {
                group[dsu.find(u)]++;
            }
            // For each set of "size", add size * (size + 1) / 2 to the number of goodPaths.
            for (auto& [_, size] : group) {
                goodPaths += (size * (size + 1) / 2);
            }
        }
        return goodPaths;
    }
};

// class Solution {
// public:

//     // 123/134 test cases passed
//     int ans = 0;
//     set<pair<int, int>> st;
//     void dfs(int node, vector<int>& vals, vector<vector<int>>& adjL, vector<bool> &visited, int parent){
//         if(visited[node]) return;
//         visited[node]=true;
//         if(node != parent){
//                 if(vals[node]==vals[parent] and st.find({node, parent})==st.end()) {
//                     ans++;
//                     st.insert({node, parent});
//                     st.insert({parent, node});
//                 }
//         }
//         for(auto &i:adjL[node]){
//             if(!visited[i]){
//                 if(vals[parent] >= vals[i]){
//                     dfs(i, vals, adjL, visited, parent);
//                 }
//             }
//         }
//     }
//     int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
//         int n = vals.size();
//         vector<vector<int>> adjL(n);
//         vector<bool> visited(n);
//         for(auto &i:edges){
//             adjL[i[0]].push_back(i[1]);
//             adjL[i[1]].push_back(i[0]);
//         }
//         for(int i=0;i<n;i++){
//             dfs(i, vals, adjL, visited, i);
//             visited = vector<bool> (n);
//         }
//         cout<<ans;
//         return ans+n;
//     }
// };