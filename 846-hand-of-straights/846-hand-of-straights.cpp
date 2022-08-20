class Solution {
public:
    bool isNStraightHand(vector<int>& nums, int k) {
                map<int, int> freq;
        for(auto i:nums){
            freq[i]++;
        }
        for(auto i: freq){
            if(freq[i.first]>0){
                for(int j=k-1;j>=0;j--){
                    cout<<freq[i.first+j]<<" ";
                    freq[i.first+j] -= freq[i.first];
                    if(freq[i.first+j]<0) return false;
                }
                
            }
        }
        
        return true;
    }
};