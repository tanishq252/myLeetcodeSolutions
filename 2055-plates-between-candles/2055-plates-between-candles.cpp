class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> candles, ans;
        for(int i=0;i<s.length();i++){
            if(s[i] == '|'){
                candles.push_back(i);
            }
        }
        for(auto query:queries){
            int i = lower_bound(candles.begin(), candles.end(), query[0])-candles.begin();
            int j = upper_bound(candles.begin(), candles.end(), query[1])-candles.begin()-1;
            ans.push_back((i<j ? (candles[j]-candles[i])-(j-i) : 0));
        }
        return ans;
    }
};