class Solution {
public:
    vector<int> countCharacters(string s){
        vector<int> count(26);
        for(auto &i:s){
            count[i-'a']++;
        }
        return count;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string> ans;
        vector<int> temp(26), count(26);
        for(auto &j:words2){
            temp = countCharacters(j);
            for(int i=0;i<26;i++){
                count[i] = max(count[i], temp[i]);
            }
        }
        
        for(auto &j:words1){
            temp = countCharacters(j);
            bool flag = false;
            for(int i=0;i<26;i++){
                if(temp[i] < count[i]){
                    flag = true;
                    break;
                }
                
            }
            if(!flag){
                    ans.push_back(j);
                }
        }
        
        return ans;
        
        
        // 45/56 test cases TLE it is ;), knew it
//         vector<string> ans;
//         vector<vector<int>> mp(words1.size(), vector<int> (26, 0));
//         for(int i=0;i<words1.size();i++){
//             for(auto &j:words1[i]){
//                 mp[i][j-'a']++;
//             }
//         }
        
//         vector<vector<int>> mp1(words2.size(), vector<int> (26, 0));
//         for(int i=0;i<words2.size();i++){
//             for(auto &j:words2[i]){
//                 mp1[i][j-'a']++;
//             }
//         }
        
//         for(int i=0;i<words1.size();i++){
//             bool flag = false;
//             for(int j=0;j<words2.size();j++){
//                 for(auto &k:words2[j]){
//                     if(mp[i][k-'a'] < mp1[j][k-'a']){
//                         flag = true;
//                         break;
//                     }
//                 }
//                 if(flag){
//                     break;
//                 }
//             }
//             if(!flag){
//                 ans.push_back(words1[i]);
//             }
//         }
        
    }
};