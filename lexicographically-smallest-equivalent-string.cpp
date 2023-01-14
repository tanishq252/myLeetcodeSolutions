// https://leetcode.com/problems/lexicographically-smallest-equivalent-string/

class Solution {
public:
    vector<int> parent;
    int find(int a){
        if(parent[a]==a) return a;
        return parent[a] = find(parent[a]);
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       parent.resize(26);
       for(int i=0;i<26;i++){
           parent[i]=i;
       }
       for(int i=0;i<s1.length();i++){
           int a = find(s1[i]-'a');
           int b = find(s2[i]-'a');
           if(a!=b){
               if(a>b){
                   parent[a]=b;
               }else{
                   parent[b]=a;
               }
           }
       }
       string ans="";
       for(auto &i:baseStr){
           int c=i-'a';
           while(parent[c]!=c){
               c = parent[c];
           }
           ans += char(c+'a');
       }
       return ans;
    }
};