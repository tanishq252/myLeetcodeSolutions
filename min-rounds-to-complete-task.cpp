// https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/
// greedy, maths, problem solving

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for(auto &i:tasks) mp[i]++;
        int ans=0;
        for(auto &i:mp){
            if(i.second<2) return -1;
            if(i.second%3==0) ans+=(i.second/3);
            else{
                while(i.second%3!=0 and i.second>0){
                    i.second-=2;
                    ans++;
                }
                ans+=(i.second/3);
            }

        }

        return ans;
    }
};