// https://leetcode.com/contest/biweekly-contest-95/problems/find-consecutive-integers-from-a-data-stream/

class DataStream {
public:
    queue<int> q;
    set<int> st;
    int v,n,c=0;
    
    DataStream(int value, int k) {
        v = value;n=k;
    }
    
    bool consec(int num) {
        if(num == v){
            c++;
        }else{
            c=0;
        }
        if(c >= n) return true;
        return false;
    }
};
