class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int i=0;
        while(i<arr.size()-1 && arr[i]<arr[i+1]){
            i++;
        }
        if(i == 0 || i == arr.size()-1){
            return false;
        }
        while(i<arr.size()-1 && arr[i]>arr[i+1]){
            i++;
        }
        if(i == arr.size()-1){
            return true;
        }
        else{return false;}
    }
};

// tried a lot but was unable to solve
// :( apna time kab aayega
