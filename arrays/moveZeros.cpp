class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter = 0;
        int counter1 = 0;
        
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 0){
                counter1++;
            }
            else{
                nums[counter++] = nums[i];
            }
        }
        for(int i=counter;i<counter1+counter;i++){
            nums[i] = 0;
        }
           
    }
};

// accepted but gave runtime earlier