class MyCalendarTwo {
public:
    map<long long int, int> bookings;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int c=0, mx=0;
        bookings[start]++; 
        bookings[end]--;
        for(auto &i:bookings){
            c+=i.second;
            if(c==3) {
                bookings[start]--; 
                bookings[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */