class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        
        for(auto i:matrix){
            if(count(i.begin(), i.end(), target)>=1){
                return true;
            }
        }
        
        return false;
    }
};