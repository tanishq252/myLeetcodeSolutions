class TimeMap {
public:
    map<string, map<int, string>> tmp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        tmp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(tmp.find(key) == tmp.end()){
            return "";
        }
         for(auto j=tmp[key].rbegin();j!=tmp[key].rend();j++){
             if(j->first<=timestamp){
                 return j->second;
             }
         }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */