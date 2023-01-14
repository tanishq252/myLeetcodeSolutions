// https://leetcode.com/problems/map-sum-pairs/description/

class TrieNode{
    public:
        // bool ends;
        vector<TrieNode*> v;

        TrieNode(){
            // this->ends = false;
            this->v = vector<TrieNode*> (26, NULL);
        }
};

class MapSum {
public:
    TrieNode *root = new TrieNode();

    void insertString(string s){
        TrieNode *t = root;
        for(auto &i:s){
            int c = i-'a';
            if(t->v[c] == NULL){
                t->v[c] = new TrieNode();
            }
            t = t->v[c];
        }
        // t->ends = true;
    }

    bool startsWith(string s){
        TrieNode *t = root;
        for(auto &i:s){
            int c = i-'a';
            if(t->v[c]==NULL) return false;
            t = t->v[c];
        }
        return true;
    }

    bool isPrefix(string s, string pref){
        for(int i=0;i<pref.size();i++){
            if(pref[i]!=s[i]) return false;
        }
        return true;
    }

    unordered_map<string ,int> mp;

    MapSum() {

    }
    
    void insert(string key, int val) {
        mp[key] = val;
        insertString(key);
    }
    
    int sum(string prefix) {
        int ans=0;
        if(!startsWith(prefix)) return 0;
        for(auto &i:mp){
            if(isPrefix(i.first, prefix)) ans+=i.second;
        }
        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */