class Solution {
public:
    void solve(vector<int> &v, int ind, int k){
        if(v.size() == 1){
            return;
        }
        ind = (ind+k)%v.size();
        v.erase(v.begin()+ind);
        solve(v, ind, k);
    }
    
    int findTheWinner(int n, int k) {
        vector<int>v (n, 0);
        for(int i=0;i<n;i++) v[i] = i+1;
        solve(v, 0, k-1);
        return v[0];
    }
};