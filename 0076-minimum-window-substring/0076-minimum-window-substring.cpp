class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> map(128,0);
        for(auto c: t) map[c]++;
        int counter=t.size(), left=0, right=0, minLen=INT_MAX, minInd=0;
        while(right<s.size()){
            if(map[s[right]]>0){
                counter--;
            }
            map[s[right]]--;
            right++;
            while(counter == 0){
                if(right-left < minLen){
                    minLen = right-left;
                    minInd = left;
                }
                map[s[left]]++;
                if(map[s[left]]>0){
                    counter++;
                }
                left++;
            }
        }
        return minLen==INT_MAX? "":s.substr(minInd, minLen);
    }
};