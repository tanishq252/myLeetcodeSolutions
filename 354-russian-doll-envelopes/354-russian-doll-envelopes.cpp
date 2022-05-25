class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        		sort(envelopes.begin(), envelopes.end(), [](vector<int>& a, vector<int>& b) // Sort Width
			 -> bool { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });

		vector<int> dp; // Longest increasing subsequence
		for(auto& envelope : envelopes) {
			int height = envelope[1];
			int index = lower_bound(dp.begin(), dp.end(), height) - dp.begin(); // Find index that have mininum value >= height 

			if(index == dp.size()) // Can't find
				dp.push_back(height);
			else 
				dp[index] = height;
		}
		
		return dp.size();
        
        // 85/87 test cases passed
        // sort(envelopes.begin(), envelopes.end());
        // vector<int> dp(envelopes.size(), 1);
        // for(int i=0;i<envelopes.size();i++){
        //     for(int j=0;j<i;j++){
        //         if(envelopes[i][0]>envelopes[j][0] and envelopes[i][1]>envelopes[j][1]){
        //             dp[i] = max(dp[i], dp[j]+1);
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
    }
};