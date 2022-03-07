class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2){return true;}
        int i=0;
        int j=s1.length()-1;
        while(i<=j){
            if(s1[i] == s2[i] && s1[j] == s2[j]){i++;j--;}
            else if(s1[i] == s2[i] && s1[j] != s2[j]){i++;}
            else if(s1[i] != s2[i] && s1[j] == s2[j]){j--;}
            else{
                swap(s2[i], s2[j]);
                break;
            }
        }
        cout<<s2<<"\n";
        return s1==s2;
    }
};