class Solution {
public:
    vector<int> grayCode(int n) {
        if(n == 1) return {0,1};
        vector<int> ans = grayCode(n-1);
        int num = pow(2, n-1);
        for(int i=ans.size()-1;i>=0;i--){
            ans.push_back(ans[i]+num);
        }
        return ans;
    }
};