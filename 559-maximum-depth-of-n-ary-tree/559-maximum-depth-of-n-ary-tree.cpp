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
    void leveltraverse(Node *root, vector<vector<int>> &level,int depth){
        if(root==NULL) return;
        if(depth == level.size()){
            level.push_back({});
        }
        level[depth].push_back(root->val);
        for(int i=0;i<root->children.size();i++){
            leveltraverse(root->children[i], level, depth+1);
        }
    }
    
    int maxDepth(Node* root) {
        vector<vector<int>> level;
        leveltraverse(root, level, 0);
        return level.size();
    }
};