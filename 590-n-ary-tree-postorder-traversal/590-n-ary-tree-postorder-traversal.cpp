/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> v;
    
    void postOrder(Node *root){
        if(root==NULL){return;}
        vector<Node*> ch = root->children;
        for(int i=0;i<ch.size();i++){
            postOrder(ch[i]);
        }
        v.push_back(root->val);
    }
    vector<int> postorder(Node* root) {
        postOrder(root);
        return v;
    }
};