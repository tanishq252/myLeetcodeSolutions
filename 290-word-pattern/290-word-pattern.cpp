class Solution {
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s);string word;
        map<char, string> mp;
        map<string, char> mp1;
        int i=0;
        while(ss>>word){
            if(mp.find(pattern[i])==mp.end() and mp1.find(word)==mp1.end()){
                mp[pattern[i]] = word;
                mp1[word] = pattern[i];
            }else{
                cout<<mp[pattern[i]]<<" ";
                if(mp[pattern[i]]!=word or mp1[word]!=pattern[i]){
                    return false;
                }
            }
            i++;
        }
        cout<<i;
        return (i==pattern.length())?true:false;
        
//         stringstream ss(s);string word;
//         string pattern1="", pattern2="";
//         map<string, int> mp1;        
//         map<char, int> mp2;

//         while(ss>>word){
//             mp1[word]++;
//         }
        
//         stringstream ss1(s);string words;

//         while(ss1>>words){
//             pattern1+= to_string(mp1[words]);
//         }
        
//         for(auto &i: pattern){
//             mp2[i]++;
//         }
//         for(auto &i: pattern){
//             pattern2+= to_string(mp2[i]);
//         }
//         cout<<pattern1<<" "<<pattern2;
        // return pattern1 == pattern2;
    }
};