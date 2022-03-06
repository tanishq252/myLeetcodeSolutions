class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int c= 0;
        for(int i=0;i<endTime.size();i++){
            if(queryTime>=startTime[i]&&queryTime<=endTime[i]){
                c++;
            }
        }
        return c;
    }
};