class MyCalendar {
public:
    vector<vector<int>> bookings;
    
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for(auto i:bookings){
            if(i[0]<end and start<i[1]) return false;
        }
        bookings.push_back({start, end});
        return true;
        // 93/107 test cases passed
        // if(bookings.size()==0) {bookings.push_back({start, end});return true;}
        // else if(bookings.size()==1){
        //     if(bookings.back()[1] <= start){
        //         bookings.push_back({start, end});
        //         sort(bookings.begin(), bookings.end());
        //         return true;
        //     }else if(bookings.front()[0] >= end){
        //         bookings.push_back({start, end});
        //         sort(bookings.begin(), bookings.end());
        //         return true;
        //     }
        // }
        // else if(bookings.size() >= 2){
        //     for(int i=0;i<bookings.size()-1;i++){
        //         if(bookings[i][1]<=start and bookings[i+1][0]>=end){
        //             bookings.push_back({start, end});
        //             sort(bookings.begin(), bookings.end());
        //             return true;
        //         }
        //     }
        //     if(bookings.back()[1] <= start){
        //         bookings.push_back({start, end});
        //         sort(bookings.begin(), bookings.end());
        //         return true;
        //     }else if(bookings.front()[0] >= end){
        //         bookings.push_back({start, end});
        //         sort(bookings.begin(), bookings.end());
        //         return true;
        //     }
        // }
        // return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */