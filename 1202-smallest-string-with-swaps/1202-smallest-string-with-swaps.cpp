class Solution {
public:
    vector<int> adj[100001];
    bool visited[100001];
    
    void DFS(string &s, int vertex,vector<char> &chars, vector<int> &indices ){
        chars.push_back(s[vertex]);
        indices.push_back(vertex);
        
        visited[vertex] = true;
        
        for(int adjacent:adj[vertex]){
            if(!visited[adjacent]){
                DFS(s, adjacent, chars, indices);
            }
        }
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        for(vector<int> edge: pairs){
            int source = edge[0];
            int destination = edge[1];
            
            adj[source].push_back(destination);
            adj[destination].push_back(source);
            
        }
        
        for(int vertex = 0;vertex<s.size();vertex++){
            if(!visited[vertex]){
                vector<int> indices;
                vector<char> chars;
                
                DFS(s, vertex, chars, indices);
                
                sort(indices.begin(), indices.end());
                sort(chars.begin(), chars.end());
                
                for(int index = 0;index<chars.size();index++){
                    s[indices[index]] = chars[index];
                }
            }
        }
        return s;
    }
};