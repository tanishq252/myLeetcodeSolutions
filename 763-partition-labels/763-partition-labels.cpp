class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> v;
        vector<int> maxLastIndex(26, 0);
        
        for(int i=0;i<s.length();i++){
            // this will store the index where the letter occurs at the max position
            maxLastIndex[s[i]-'a'] = i;
        }
        
        int j=0;// to store the maxLastIndex of the first element of partition
        string t="";
        for(int i=0;i<s.length();i++){
            j = max(j, maxLastIndex[s[i]-'a']);
            t += s[i];
            if(i==j){
                v.push_back(t.length());
                t=""; j=0;
            }
        }
        return v;
    }
};