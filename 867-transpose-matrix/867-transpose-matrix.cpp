class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        vector<vector<int>> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for (int i = 0;i<cols;i++){
            ans.push_back({});
            for(int j = 0;j<rows;j++){
                ans[i].push_back(matrix[j][i]);
            }
        }
        return ans;
    }
};