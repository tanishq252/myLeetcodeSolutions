class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto i:words){
            string s1 = i;
            for(int j=i.length()-1,k=0;j>=0;j--,k++){
                s1[j] = i[k];
            }
            if(s1 == i){
                return i;
            }
        }
        return "";
    }
};