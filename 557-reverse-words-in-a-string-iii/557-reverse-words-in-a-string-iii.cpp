class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word, ans="";
        while(ss>>word){
            reverse(word.begin(), word.end());
            ans+= word+" ";
        }
        ans.pop_back();
        return ans;
    }
};