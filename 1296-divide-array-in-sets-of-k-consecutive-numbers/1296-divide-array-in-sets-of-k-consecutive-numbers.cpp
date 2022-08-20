class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> freq;
        for(auto i:nums){
            freq[i]++;
        }
        for(auto i: freq){
            if(freq[i.first]>0){
                for(int j=k-1;j>=0;j--){
                    freq[i.first+j] -= freq[i.first];
                    if(freq[i.first+j]<0) return false;
                }
            }
        }
        
        return true;
        
        // 35/60 test cases passed
//         sort(nums.begin(), nums.end());
//         map<int, int> freq;
//         set<int> st(nums.begin(), nums.end());
//         int c = 0;
//         for(auto i:nums){
//             freq[i]++;
//         }
//         int ind = 0, p1=0, p2=0, i=0, j=0;
//         while(i<nums.size()){
//             freq[i]--;
//             cout<<freq[i]<<" ";
//             if(freq[i]==0) p1++;
//             i++;j++;
            
//             if(j%k==0){
//                                     cout<<i<<" "<<j<<" "<<p1<<"\n";

//                 if(i==st.size() and j == nums.size() and p1!=0){
//                     return true;
//                 }
//                 i-=p1;p1=0;
//             }
//             if(i==st.size() and p1!=0){
//                 return false;
//             }
//         }
        
    }
};