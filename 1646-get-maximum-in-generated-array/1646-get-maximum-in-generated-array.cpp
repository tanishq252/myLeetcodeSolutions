class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int> ans;
        if(n==0){
            return 0;
        }
        ans.push_back(0);        ans.push_back(1);
        for(int i=2;i<=n;i++){
            if(i%2==0){
                ans.push_back(ans[i/2]);
            }else{
                ans.push_back(ans[i/2]+ans[(i/2)+1]);
            }
        }
        for(auto i:ans){
            cout<<i<<" ";
        }
        return *max_element(ans.begin(), ans.end());
    }
};