class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int a = s1.length();        
        int b = s2.length();
        if(a>b){
            return false;
        }
        vector<int> window1(26, 0);        
        vector<int> window2(26, 0);
        for(int i=0;i<a;i++){
            window1[s1[i]-'a']++;            
            window2[s2[i]-'a']++;
        }
        
        if (window1 == window2) return true;
        
        for(int i=a;i<b;i++){
            window2[s2[i-a]-'a']--;            
            window2[s2[i]-'a']++;
            if (window1 == window2) return true;
        }

        return false;

    }
};