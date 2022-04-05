class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxAmt = 0;
        int start = 0, end = height.size()-1;
        while(end>start){
            maxAmt = max(maxAmt, min(height[start], height[end])*(end-start));
            if(height[start]>height[end]){
                end--;
            }else{
                start++;
            }
        }
        return maxAmt;
    }
};