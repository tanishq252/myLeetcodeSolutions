class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        return find(arr.begin(), arr.end(), *max_element(arr.begin(), arr.end()))-arr.begin();
    }
};