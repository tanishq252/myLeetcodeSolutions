class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int counter = 0;
        for(int i=0;i<words.size();i++){
            int flag = 0;
            for(int j=0;j<words[i].length();j++){
                if(allowed.find(words[i][j]) == string::npos){
                    flag = 1;
                }
            }
            if(flag == 1) counter++;
            
            
        }
        return words.size()- counter;
    }
};