#include <bits/stdc++.h>
using namespace std;

int main(){

    vector<int> nums1 = {1,2,3,5,0,0,0};
    vector<int> nums2 = {2,5,5};
    int m = 4;
    int n = ;
    int c=0;
    if(n!=0){
        for(int i=0;i<m+n;i++){
        if(nums1[i] >= nums2[c] && c<=n-1){
            nums1.insert(nums1.begin()+i,nums2[c] );
            nums1.pop_back();
            c++;
        }
        else if(nums1[i] == 0 && c<=n-1){
            nums1.insert(nums1.begin()+i,nums2[c] );
            nums1.pop_back();
            c++;
        }
    }
    }

    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<" ";
    }
     
}

// solution 
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
	while (j >= 0) {
		if (i < 0 || nums2[j] >= nums1[i]) {
			nums1[k] = nums2[j];
			j--;
		} else {
			nums1[k] = nums1[i];
			i--;
		}
		k--;
	}
    }
};