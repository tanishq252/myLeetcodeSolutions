class MyCalendarThree {
public:
    map<long long int, int> eventsFreq;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int maxEvents=0;
        int currentEvents=0;
        eventsFreq[start]++;
        eventsFreq[end]--;
        for(auto &i:eventsFreq){
            currentEvents+=i.second;
            maxEvents=max(maxEvents, currentEvents);
        }
        return maxEvents;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */