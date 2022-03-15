class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int target) {
        vector<pair<int, int>> v;
        int ans=0;
        for(auto i:boxTypes){
            v.push_back(make_pair(i[1], i[0]));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i=0;i<v.size();i++){
            ans+= (target>v[i].second)? (v[i].first*v[i].second):(v[i].first*target);
            if(target>v[i].second){
                target-=v[i].second;
                // ans+=(v[i].first*v[i].second);
            }
            else{
                // ans+=(v[i].first*target);
                break;
            }
        }
        return ans;
    }
};