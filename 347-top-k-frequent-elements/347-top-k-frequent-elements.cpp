class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        vector<int> ans;
        vector<pair<int, int>> v;
        set<int> s;
        int n = nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            s.insert(nums[i]);
        }
        vector<int> uv(s.begin(), s.end());
        for(int i=0;i<uv.size();i++){
            v.push_back(make_pair(m[uv[i]], uv[i]));
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        for(int i=k, j=0;i>0;i--, j++){
            ans.push_back(v[j].second);
        }
        return ans;
    }
};