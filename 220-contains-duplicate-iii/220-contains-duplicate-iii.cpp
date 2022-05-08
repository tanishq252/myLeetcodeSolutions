class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        vector<pair<long long int, int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(abs(v[i].first - v[j].first)<=t){
                    if(abs(v[i].second - v[j].second)<=k){return true;}
                }else{
                    break;
                }
            }
        }
        return false;
    }
};