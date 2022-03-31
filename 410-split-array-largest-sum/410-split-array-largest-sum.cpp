class Solution {
public:
    
    int mem[1001][51];
    
    int getMinLargestSplit(vector<int> &prefixSum, int currentIndex, int subArrayCount ){
        int n = prefixSum.size()-1;
        if(mem[currentIndex][subArrayCount]!=-1){
            return mem[currentIndex][subArrayCount];
        }
        
        if(subArrayCount == 1){
            return mem[currentIndex][subArrayCount] = prefixSum[n]-prefixSum[currentIndex];
        }
        
        int minLargestSplitSum = INT_MAX;
        for(int i=currentIndex; i<=n-subArrayCount;i++){
            int firstSplitSum = prefixSum[i+1]-prefixSum[currentIndex];
            int largestSplitSum = max(firstSplitSum, getMinLargestSplit(prefixSum, i+1, subArrayCount-1));
            minLargestSplitSum = min(minLargestSplitSum, largestSplitSum);
            if(firstSplitSum>=largestSplitSum){
                break;
            }
        }
        return mem[currentIndex][subArrayCount] = minLargestSplitSum;
    }
    
    int splitArray(vector<int>& nums, int m) {
        memset(mem, -1, sizeof(mem));
        vector<int> prefixSum(nums.size()+1, 0);
        for(int i=0;i<nums.size();i++){
            prefixSum[i+1] = prefixSum[i]+nums[i];
        }
        
        return getMinLargestSplit(prefixSum, 0, m);
        
    }
};