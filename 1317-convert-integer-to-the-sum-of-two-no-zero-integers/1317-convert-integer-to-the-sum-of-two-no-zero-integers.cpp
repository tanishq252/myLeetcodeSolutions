class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        int i, j;
        i = (n/10)*10;
        j = n%10;
        if(i<j){
            return {i+1, j-1};
        }

        while(true){
            if(i%10!=0 and j%10!=0){
                if((to_string(i).find('0')>to_string(i).length()) and to_string(j).find('0')>to_string(j).length()){
                    return{i, j};
                }
            }
            i--;j++;
        }
        return {i, j};
    }
};