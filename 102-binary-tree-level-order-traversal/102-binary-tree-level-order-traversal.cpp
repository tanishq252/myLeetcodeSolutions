/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void lvlOrd(vector<vector<int>> &v, int depth, TreeNode *root){
        if(root == NULL) return;
        if(v.size() ==  depth) v.push_back({});
        v[depth].push_back(root->val);
        lvlOrd(v, depth+1, root->left);        
        lvlOrd(v, depth+1, root->right);

    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        lvlOrd(v, 0, root);
        return v;
    }
};