class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        for(auto i:intervals){
            if(ans.empty()){
                ans.push_back(i);
            }else{
                if(ans.back()[1] >= i[0]){
                    if(ans.back()[1] < i[1]){
                       ans.back()[1] = i[1] ;
                    }
                }else{
                    ans.push_back(i);
                }
            }
        }
        return ans;
    }
};