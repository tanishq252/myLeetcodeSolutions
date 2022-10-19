class Solution {
public:
    int calcPivot(int low, int high, vector<int> &nums){
        int pivot = nums[high];
        int i=low;
        for(int j=low; j<high; j++){
            if(nums[j]<=pivot){
                swap(nums[i++], nums[j]);
            }
        }
        swap(nums[i], nums[high]);
        return i;
    }
    
    void quicksort(int low, int high, vector<int>& nums){
        if(high>low){
            int pivot = calcPivot(low, high, nums);
            quicksort(low, pivot-1, nums);
            quicksort(pivot+1, high, nums);
        }
    }
    
    void mergeSort(int low, int high, vector<int> &nums){
        if(high>low){
            int mid = (high+low)/2;
            mergeSort(low, mid, nums);
            mergeSort(mid+1, high, nums);
            mergeArrays(low, high, mid, nums);
        }else{
            return;
        }
    }
    
    void mergeArrays(int low, int high, int mid, vector<int> &nums){
        if(low>=high) return;
        int h=high, m=mid, l=low;
        int i=low, j=mid+1, k=0;
        vector<int> dummy(high-low+1, 0);
        while(i<=mid and j<=high){
            if(nums[i] > nums[j]){
                dummy[k++] = nums[j++];
            }else{
                dummy[k++] = nums[i++];
            }
        }
        while(i<=mid){
            dummy[k++] = nums[i++];
        }
        while(j<=high){
            dummy[k++] = nums[j++];
        }
        for(int i=0;i<high-low+1;i++){
            nums[low+i] = dummy[i];
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        // quicksort(0, nums.size()-1, nums);
        mergeSort(0, nums.size()-1, nums);
        return nums;
    }
};