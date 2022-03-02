class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> v;
        v.push_back(0);
        for(int i=0;i<gain.size();i++){
            v.push_back(v[i]+gain[i]);
        }
        return *max_element(v.begin(), v.end());
    }
};