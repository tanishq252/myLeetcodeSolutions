class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.length() < p.length()) return {};
        vector<int> window(26, 0);            
        vector<int> window2(26, 0);        
    
        int sl = s.length();        
        int pl = p.length();
        for(int i=0;i<pl;i++){
            window[p[i]-'a']++;            
            window2[s[i]-'a']++;

        }
        vector<int> ans;
        if(window == window2){
            ans.push_back(0);
        }
        for(int i=pl; i<sl;i++){
            window2[s[i-pl] - 'a']--;
            window2[s[i] - 'a']++;
            
            if(window == window2){
                ans.push_back(i-pl+1);
            }
        }
        
        return ans;
    }
};