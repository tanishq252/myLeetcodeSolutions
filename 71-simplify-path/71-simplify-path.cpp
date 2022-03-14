class Solution {
public:
    string simplifyPath(string path) {
        string s="/";
        if(path=="/"||path=="/.."||path=="/."){return "/";}
        vector<string> v;
        path+="/";
        string t="";
        for(int i=0;i<path.length();i++){
            if(path[i]=='/'){
                if(t == ".."){
                    if(v.size()>0){
                        v.pop_back();
                    }
                }
                else if(t == "."||t == ""){
                }
                else{
                    v.push_back(t);
                }
                t = "";
            }
            else{
                t+=path[i];
            }
        }
        cout<<t;
        
        if(v.size() == 0){return "/";}
        
        for(int i=0;i<v.size()-1;i++){
            s+=v[i];
            s+="/";
        }
        s+=v[v.size()-1];
        
        return s;
    }
};