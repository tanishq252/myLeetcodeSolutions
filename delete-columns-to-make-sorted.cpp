// https://leetcode.com/problems/delete-columns-to-make-sorted/submissions/870176820/

    int minDeletionSize(vector<string>& strs) {
        int ans=0;
        for(int j=0;j<strs[0].size();j++){
            for(int i=0;i<strs.size()-1;i++){
                if(strs[i][j] > strs[i+1][j]){
                    ans++;break;
                }
            }
        }
        return ans;
    }