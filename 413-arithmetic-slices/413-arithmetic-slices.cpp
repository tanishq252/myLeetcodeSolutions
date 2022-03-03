class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int c = 0;
        int c1 = 0;
        int n = nums.size();
        if(n<3){return 0;}
        for(int i=3;i<=n;i++){
            for(int j=0;j<=n-i;j++){
                for(int k= 0 ;k < i-2;k++){
                    if((nums[j+k]-nums[j+k+1]) != (nums[j+k+1]-nums[j+k+2])){
                        c1++; break;
                    }
                }
                c++;
            }
            
        }
        return c-c1;
    }
};