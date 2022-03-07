class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        triangle.push_back({1});  
        triangle.push_back({1,1});
        for(int i=2;i<=33;i++){
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<i;j++){
                v.push_back(triangle[i-1][j-1]+triangle[i-1][j]);
            }
            v.push_back(1);
            triangle.push_back(v);
        }
        return triangle[rowIndex];
    }
};