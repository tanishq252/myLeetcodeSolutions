class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        int c = INT_MIN;
        for(auto i:arr){
            mp[i]++;
            
        }
        for(auto i:mp){
            if(i.first == i.second){
                c = max(c, i.first);
            }
        }
        return c==INT_MIN ? -1 : c;
    }
};