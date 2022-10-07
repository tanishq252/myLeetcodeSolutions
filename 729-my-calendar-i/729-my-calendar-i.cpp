class MyCalendar {
public:
    map<long long int, int> bookings;    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int c=0, mx=0;
        bookings[start]++; 
        bookings[end]--;
        for(auto &i:bookings){
            c+=i.second;
            if(c==2) {
                bookings[start]--; 
                bookings[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */