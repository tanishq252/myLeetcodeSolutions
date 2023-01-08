// https://leetcode.com/contest/weekly-contest-327/problems/maximum-count-of-positive-integer-and-negative-integer/

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int c=0, c1=0;
        for(auto &i:nums){
            if(i<0) c1++;
            else if(i>0) c++;
        }
        return max(c, c1);
    }
};