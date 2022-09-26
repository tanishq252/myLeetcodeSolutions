class Solution {
public:
    vector<int> parent;
    
    int find(int x){
        if(x==parent[x]) return parent[x];
        return parent[x] = find(parent[x]);
    }

    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        for(int i=0;i<26;i++) parent[i] = i;
        for(auto &i:equations){
            if(i[1]=='='){
                parent[find(i[0]-'a')] = find(i[3]-'a');
            }
        }
        for(auto &i:equations){
            if(i[1]=='!' and find(i[0]-'a') == find(i[3]-'a')){
                return false;
            }
        }
        return true;
    }
};