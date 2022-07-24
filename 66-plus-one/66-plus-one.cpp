class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        digits[n-1]+=1;
        vector<int> ans(n+1, 0);
        for(int i=n;i>0;i--){
            ans[i-1] = (ans[i]+digits[i-1])/10;
            ans[i] = (ans[i]+digits[i-1])%10;
            
        }
        return (ans[0]==0)?vector<int> (ans.begin()+1, ans.end()) : ans;
    }
};