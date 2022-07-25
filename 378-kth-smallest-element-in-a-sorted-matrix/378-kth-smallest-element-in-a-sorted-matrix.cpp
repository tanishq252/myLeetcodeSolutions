class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        // kthe element provided each element is ditcinct
        // int n = matrix.size();
        // if(k%n == 0){
        //     if(k/n == n){
        //         return matrix[n-1][n-1];
        //     }else{
        //         return matrix[(k/n) - 1][n-1];
        //     }
        // }else{
        //     return matrix[k/n][(k%n)-1];
        // }
        
        int n = matrix.size();
        vector<int> ans;
        for(auto i:matrix){
            for(auto j:i){
                ans.push_back(j);
            }
        }
        sort(ans.begin(), ans.end());

        return ans[k-1];
    }
};