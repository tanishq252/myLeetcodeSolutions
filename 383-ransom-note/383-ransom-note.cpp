class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> note(26, 0);        
        vector<int> mag(26, 0);
        for(auto i:ransomNote){
            note[i-'a']++;
        }
        for(auto i:magazine){
            mag[i-'a']++;
        }
        for(auto i:ransomNote){
            if(note[i-'a']>mag[i-'a']){
                return false;
            }
        }
        
        return true;
        

    }
};