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
    
    void preOrder(Node *root){
        if(root==NULL){return;}
        v.push_back(root->val);
        vector<Node*> ch = root->children;
        for(int i=0;i<ch.size();i++){
            preOrder(ch[i]);
        }
    }
    vector<int> preorder(Node* root) {
        preOrder(root);
        return v;
    }
};