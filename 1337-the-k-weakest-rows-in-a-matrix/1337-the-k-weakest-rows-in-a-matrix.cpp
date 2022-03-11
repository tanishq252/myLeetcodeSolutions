class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vec;
        for(int i=0;i<mat.size();i++){
            vec.push_back(make_pair(count(mat[i].begin(), mat[i].end(), 1), i));
        }
        sort(vec.begin(), vec.end());
        vector<int> v;
        for(int i=0;i<k;i++){
            v.push_back(vec[i].second);
        }
        return v;
    }
};