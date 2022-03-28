class Solution {
public:
    void solve(vector<int> &v, int ind, int k){
        ind = (ind+k)%v.size();
        if(v.size()==1){return;}
        v.erase(v.begin()+ind);
        solve(v, ind, k);
    }
    
    int findTheWinner(int n, int k) {
        vector<int> v;
        int ans=0, ind = 0;
        for(int i=0;i<n;i++){
            v.push_back(i+1);
        }
        solve(v, ind, k-1);
        return v[0];
    }
};