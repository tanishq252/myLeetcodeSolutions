class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int arrB, lvB, arrA, lvA;
        int days=0;
        for(int i=0;i<stoi(arriveAlice.substr(0, 2))-1;i++){
            days+=months[i];
        }
        arrA = days+stoi(arriveAlice.substr(3, 2));
        days = 0;
        for(int i=0;i<stoi(leaveAlice.substr(0, 2))-1;i++){
            days+=months[i];
        }
        lvA = days+stoi(leaveAlice.substr(3, 2));
        days = 0;
        for(int i=0;i<stoi(arriveBob.substr(0, 2))-1;i++){
            days+=months[i];
        }
        arrB = days+stoi(arriveBob.substr(3, 2));
        days = 0;
        for(int i=0;i<stoi(leaveBob.substr(0, 2))-1;i++){
            days+=months[i];
        }
        lvB = days+stoi(leaveBob.substr(3, 2));
        cout<<arrA<<" "<<lvA<<" "<<arrB<<" "<<lvB;
        if(arrB > lvA or arrA > lvB){
            return 0;
        }
        else if(lvA >= arrB){
            if(lvA > lvB){
                return lvB-max(arrB, arrA)+1;
            }
            return lvA-max(arrB, arrA)+1;
        }else if(lvB >= arrA){
            if(lvA < lvB){
                return lvA-max(arrB, arrA)+1;
            }
            return lvB-max(arrB, arrA)+1;
        }
        return 0;
    }
};