class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        vector<int> v;
        for(int i=0;i<rectangles.size();i++){
            v.push_back(min(rectangles[i][0], rectangles[i][1]));
        }
        int max = *max_element(v.begin(), v.end());
        return count(v.begin(), v.end(), max);
    }
};