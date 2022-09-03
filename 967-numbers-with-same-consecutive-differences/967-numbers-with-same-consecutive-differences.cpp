class Solution {
public:
    
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> ans = {1,2,3,4,5,6,7,8,9};
        for(int i=1;i <n ;i++){
            vector<int> tempAns;
            for(auto x:ans){
                int y = x%10;
                if(y+k<10){
                    tempAns.push_back((x*10)+y+k);
                }
                if(y>=k and k>0){
                    tempAns.push_back((x*10)+y-k);
                }
            }
            ans = tempAns;
        }
        
        return ans;
//         53/81 cases passed (bad time is going on but try try don't cri)
        // set<int> ans;
        // vector<vector<string>> vec;
        // int i=0;
        // while(i+k<=9){
        //     if(i!=0){
        //         vec.push_back({to_string(i), to_string(i+k)});    
        //     }
        //     if(k!=0){
        //         vec.push_back({to_string(i+k), to_string(i)});
        //     }
        //     i++;
        // }
        // for(auto i:vec){
        //     int j=0;string s="";
        //     while(j<n){
        //         s+=i[j%2];j++;
        //     }
        //     if(s.length() == n){
        //         int num = stoi(s);
        //         ans.insert(num);
        //     }
        // }
        // return vector<int>(ans.begin(), ans.end());
    }
};