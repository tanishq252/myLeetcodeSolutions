class Solution {
public:
    string simplifyPath(string path) {
        string s;
        if(path=="/"||path=="/.."||path=="/."){return "/";}
        vector<string> v;
        string t="";
        for(int i=0;i<path.length();i++){
            t="";
            while(i<path.length()&&path[i]!='/'){
                t+=path[i]; i++;
            }
            if(t==".."){
                if(v.empty()==false){
                    v.pop_back();
                }
            }
            else if(t==""||t=="."){}
            else{
                v.push_back(t);
            }
        }
        for(int i=0;i<v.size();i++){
            s+= "/"+v[i];
        }
        
        return (s=="")?"/" : s;
    }
};