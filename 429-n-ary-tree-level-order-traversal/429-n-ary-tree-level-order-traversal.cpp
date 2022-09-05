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
    vector<vector<int>> v;
    void level(Node *root, int depth){
        if(root == NULL) return;
        if(v.size() == depth){
            v.push_back({});
        }
        v[depth].push_back(root->val);
        for(auto &i:root->children){
            level(i, depth+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        level(root, 0);
        return v;
    }
};