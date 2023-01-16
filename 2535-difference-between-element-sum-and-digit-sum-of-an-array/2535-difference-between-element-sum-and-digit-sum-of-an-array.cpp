class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int su = accumulate(nums.begin(), nums.end(), 0);
        int s2 = 0;
        string s="";
        for(auto &i:nums){
            s = to_string(i);
            if(s.length()>1){
                for(int j=0;j<s.length();j++){
                    s2 += (s[j]-'0');
                }
            }else{
                s2 += i;
            }
        }
        return abs(su-s2);
    }
};