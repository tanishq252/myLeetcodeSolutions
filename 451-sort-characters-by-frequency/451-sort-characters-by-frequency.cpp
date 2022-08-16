class Solution {
public:
    string frequencySort(string s) {
        string ans = "";
        vector<pair<int, char>> v;
        set<char> st(s.begin(), s.end());
        for(auto i:st){
            v.push_back({count(s.begin(), s.end(), i), i});
        }
        sort(v.begin(), v.end(), [](pair<int, char> a,pair<int, char> b){
            return a.first>b.first;
        });
        for(auto i:v){
            cout<<i.first<<" "<<i.second<<"\n";
            for(int j=0;j<i.first;j++){
                ans+=i.second;
            }
        }
        return ans;
    }
};