class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> st;
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(auto i:words){
            string s = "";
            for(auto j:i){
                s+= v[j-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};