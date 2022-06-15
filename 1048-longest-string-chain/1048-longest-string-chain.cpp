class Solution {
public:
    static bool compare(string s1, string s2)
    {
        return s1.size()<s2.size();
    }
    
    int longestStrChain(vector<string>& words) 
    {
        unordered_map<string, int> dp; //it stores predecessor word and chain size

        sort(words.begin(), words.end(), compare);
        
        int len = 1; 
        for(auto w:words) 
        {
            dp[w]=1; 
            for(int i=0; i<w.length(); i++) 
            {
                string p = w.substr(0, i)+w.substr(i+1);
                if(dp.find(p)!=dp.end()){
                    dp[w] = dp[p]+1;
                    len = max(len, dp[w]);
                }
            }
        }
        return len;    
    }

};