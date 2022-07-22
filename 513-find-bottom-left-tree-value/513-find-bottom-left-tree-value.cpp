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
    void levelOrder(TreeNode *root, vector<vector<int>> &levels, int depth){
        if(root == NULL) return;
        if(levels.size() == depth){
            levels.push_back({});
        }
        levels[depth].push_back(root->val);
        levelOrder(root->left, levels, depth+1);
        levelOrder(root->right, levels, depth+1);
    }
    
    int findBottomLeftValue(TreeNode* root) {
        vector<vector<int>> levels;
        levelOrder(root, levels, 0);
        return levels[levels.size()-1][0];
    }
};