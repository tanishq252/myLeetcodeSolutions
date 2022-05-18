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
    void levelorder(Node *root, vector<vector<int>> &ans, int depth){
        if(root==NULL) return;
        if(ans.size() == depth) ans.push_back({});
        ans[depth].push_back(root->val);
        vector<Node *> children = root->children;
        for(int i=0;i<children.size();i++){
            levelorder(root->children[i], ans, depth+1);
        }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        levelorder(root, ans, 0);
        return ans;
    }
};