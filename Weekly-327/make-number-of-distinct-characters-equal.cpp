// https://leetcode.com/problems/make-number-of-distinct-characters-equal/description/

class Solution {
public:
    bool isItPossible(string word1, string word2) {
        vector<int> v1(26),v2(26),v3,v4;  
        set<int> s1,s2;
        for(auto &i:word1) v1[i-'a']++;        
        for(auto &i:word2) v2[i-'a']++;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                if(v1[i]>0 and v2[j]>0){
                    v3 = v1;
                    v4 = v2;
                    v3[i]--;
                    v3[j]++;
                    v4[i]++;
                    v4[j]--;
                    for(int i=0;i<26;i++){
                        if(v3[i]>0) s1.insert(i);                        
                        if(v4[i]>0) s2.insert(i);
                    }
                    if(s1.size() == s2.size()) return true;
                    s1.clear();                    
                    s2.clear();
                }
            }
        }
        return false;

    }
};