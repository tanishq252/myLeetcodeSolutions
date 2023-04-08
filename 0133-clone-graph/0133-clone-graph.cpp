/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        map<Node*, Node*> mp;
        mp[node] = new Node(node->val);
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node *topNode = q.front();
            q.pop();
            for(auto i:topNode->neighbors){
                if(mp.find(i)==mp.end()){
                    mp[i] = new Node(i->val);
                    q.push(i);
                }
                mp[topNode]->neighbors.push_back(mp[i]);
            }
        }
        
        return mp[node];
        
//         Node *clone = new Node(node->val);
//         queue<Node*> q;       
//         queue<Node*> q1;
//         q.push(node);        
//         q1.push(clone);
//         vector<bool> visited(101, false);
//         visited[node->val] = true;
        
//         while(!q.empty()){
//             Node *topNode = q.front();
//             Node *topCloneNode = q1.front();
//             q.pop();q1.pop();
//             for(auto i:topNode->neighbors){
//                 Node *newNode = new Node(i->val);
//                 if(!visited[i->val]){
//                     visited[i->val] = true;
//                     q.push(i);
//                     q1.push(newNode);
//                 }
//                 topCloneNode->neighbors.push_back(newNode);
//                 cout<<topCloneNode->val <<" "<<newNode->val<<"\n";
//             }
//             cout<<"\n";
//         }
        
//         return clone;
    }
};