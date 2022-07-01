class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        for(int i=0;i<rocks.size();i++){
            capacity[i]-=rocks[i];
        }
        sort(capacity.begin(), capacity.end());
        int c=0;
        for(int i=0;i<rocks.size();i++){
            if(additionalRocks == 0 or additionalRocks < capacity[i]){break;}
            additionalRocks -= capacity[i];
            capacity[i] = 0;
        }
        return count(capacity.begin(), capacity.end(), 0);
    }
};