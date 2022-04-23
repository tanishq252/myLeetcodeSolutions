class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int start = 0;
        int end =0;
        string temp="";
        for(int i=0;i<s.length()-1;i++){
            if(s[i]==s[i+1]){
                int c=0;
                start = i;
                vector<int> v;
                while(s[i]==s[i+1]){
                     i++;
                    c++;
                }
                if(c>=2){
                    v.push_back(start);
                    v.push_back(i);
                    ans.push_back(v);
                }
                start = i;
            }
            
        }
        return ans;
    }
};