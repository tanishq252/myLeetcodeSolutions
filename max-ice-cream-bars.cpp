// https://leetcode.com/problems/maximum-ice-cream-bars/
// greedy, sorting

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        if(coins<costs[0]) return 0;
        for(int i=1;i<costs.size();i++){
            costs[i]+=costs[i-1];
            if(coins<costs[i]) return i;
        }
        return costs.size();
    }
};