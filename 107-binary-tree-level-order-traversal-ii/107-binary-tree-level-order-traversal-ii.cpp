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
    vector<vector<int>> levels;
    
    void levelOrder(TreeNode *root,int depth){
        if(root == NULL) return;
        if(depth == levels.size()){
            levels.push_back({});
        }
        levels[depth].push_back(root->val);
        levelOrder(root->left, depth+1);
        levelOrder(root->right, depth+1);
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        levelOrder(root, 0);
        reverse(levels.begin(), levels.end());
        return levels;
    }
};