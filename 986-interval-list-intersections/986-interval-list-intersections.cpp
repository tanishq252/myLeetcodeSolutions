class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        if(firstList.size()==0 or secondList.size()==0) return {};
        vector<vector<int>> ans;
        for(int i=0;i<firstList.size();i++){
            for(int j=0;j<secondList.size();j++){
                int k = max(firstList[i][0], secondList[j][0]);            
                int l = min(firstList[i][1], secondList[j][1]);
                if(k>l){continue;}
                else{
                    ans.push_back({k, l});
                };
            }
        }
        return ans;
    }
};