class Solution {
public:
    map<string, map<string, double>> edges;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> ans;
        for(int i=0;i<values.size();i++){
            edges[equations[i][0]][equations[i][1]] = values[i];
            edges[equations[i][1]][equations[i][0]] = 1/values[i];

        }
        set<string> visited;
        for(int i=0;i<queries.size();i++){
            visited.insert(queries[i][0]);
            ans.push_back(dfs(queries[i][0], queries[i][1], visited));
            visited.clear();
        }
        return ans;
    }
    
    double dfs(string s1, string s2, set<string> &visited){
        visited.insert(s1);
        if(edges.count(s1) == 0 || edges.count(s2)==0){
            return -1.0;
        }
        else if(s1 == s2){
            return 1.0;
        }
        else{
            for(auto &[next, val]:edges[s1]){
                if(!visited.count(next)){
                    double r = dfs(next, s2, visited);
                    if(r>0){
                        return r*val;
                    }
                }
            }
        }
        
        
        return -1.0;

        
    }
};