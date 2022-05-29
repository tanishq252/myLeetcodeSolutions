class Solution {
public:
    
    // 151/167 cases passed using this function
    bool checkStrings(string s1, string s2){
        vector<int> visited(26, 0);
        for(auto i:s1){
            visited[i-'a'] = 1;
        }
        for(auto i:s2){
            if(visited[i-'a']) return true;
        }
        return false;
    }
    

    int maxProduct(vector<string>& words) {
        int n = words.size();
        int mx = INT_MIN;
        vector<int> bitmasks;
        for(auto i:words){
            int bitMask = 0;
            for(auto j:i){
                bitMask |= 1<<(j-'a');
            }
            bitmasks.push_back(bitMask);
        }

        for(int i=0;i<n;i++){
            for(int j = i+1;j<n;j++){
                if((bitmasks[i]&bitmasks[j])>0){
                    continue;
                }
                int mul = words[i].length()*words[j].length();
                mx = max(mx, mul);
            }
        }
        return (mx==INT_MIN)?0:mx;
    }
};