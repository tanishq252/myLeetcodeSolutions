class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string> s;
        vector<string> v1;
        for(auto i:words){
            string pattern ="";
            for(int j=0;j<i.length();j++){
                pattern+= v[i[j]-97];
            }
            s.insert(pattern);
        }
        return s.size();
    }
};