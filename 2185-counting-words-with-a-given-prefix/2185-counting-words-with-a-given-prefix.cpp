class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n = pref.length();
        int c =0 ;
        for(auto i:words){
            
            if(i.substr(0, pref.length()) == pref){
                c++;
            }
//             passed all test cases
            // int flag = 0;
            // for(int j=0;j<n;j++){
            // if(i[j]!=pref[j]){
            //     flag = 1;
            //     break;
            //     }
            // }
            // if(flag == 0){c++;}
        }
        return c;
    
    }
};