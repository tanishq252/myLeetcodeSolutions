class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if(num%3 != 0) return {};
        vector<long long> ans(3, 0);
        long long int t = num/3;
        ans[0] = t-1;
        ans[1] = t;
        ans[2] = t+1;
        return ans;
    }
};