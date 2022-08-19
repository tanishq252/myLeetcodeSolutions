class Solution {
public:
    bool isPossible(vector<int>& nums) {
        map<int, int> freq, endingInt;
        // frequencies of all elements
        for(auto i: nums){
            freq[i]++;
        }
        for(auto i:nums){
            if(freq[i]==0) continue;
            freq[i]--;
            if(endingInt[i-1]>0){
                endingInt[i-1]--;
                endingInt[i]++;
            }
            else if(freq[i+1]>0 and freq[i+2]>0){
                freq[i+1]--;
                freq[i+2]--;
                endingInt[i+2]++;
            }else{
                return false;
            }
        }
        return true;
    }
};