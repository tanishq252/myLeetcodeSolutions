class Solution {
public:
    int smallestEqual(vector<int>& nums) {
        int min = INT_MAX;
        int flag = 0 ;
        for(int i=0;i<nums.size();i++){
            if(i%10 == nums[i] && min>i){
                min = i;flag = 1;
            }
        }
        return (flag == 1)?min:-1;
    }
};