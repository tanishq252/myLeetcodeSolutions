class Solution {
public:
    bool isPrefix(const string &s1, const string &s2){
        for(int i = 0, j = 0 ; i < s1.size() && j < s2.size(); ++i , ++j ){
            if(s1[i] != s2[j])  return false;
        }
        return true;
    }
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> w;
        
        for(auto &s : words){
            reverse(s.begin(), s.end());
            w.push_back(s);
        }
        
        sort(w.begin(), w.end());

        int ans = 0;
        for(int i = 0; i < w.size(); ++i){
            if(i < w.size() -1 && isPrefix(w[i] , w[i + 1])) continue;
            else{
                ans += 1 + w[i].size();
            }
        }
        return ans;
    }

};