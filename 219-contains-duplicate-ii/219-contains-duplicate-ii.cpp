class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<long long int, int>> v;
        set<int> s;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],i});
            s.insert(nums[i]);
        }
        if(s.size()==v.size()){return false;}
        sort(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                if(v[i].first == v[j].first){
                    if(abs(v[i].second - v[j].second)<=k) return true;
                }
                else{
                    break;
                }
            }
        }
        return false;
    }
};