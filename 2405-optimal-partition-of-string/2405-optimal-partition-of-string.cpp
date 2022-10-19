class Solution {
public:
    int partitionString(string s) {
        int count=0;
        map<int, char> mp;
        int n = s.length();
        for(int i=0;i<n;i++){
            if(mp[s[i]]>0){
                mp.clear();
                count++;
            }
            mp[s[i]]++;
        }
        return count+1;
    }
};