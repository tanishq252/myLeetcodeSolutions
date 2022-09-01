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
    int ans = 0;
    
    void checkPath(TreeNode *root, int val){
        if(root == NULL) return;
        if(root->val >= val) ans++;
        checkPath(root->left, max(root->val, val));
        checkPath(root->right, max(root->val, val));
    }
    
    int goodNodes(TreeNode* root) {
        vector<int> path(100000, -10001);
        checkPath(root, -10001);
        return ans;
    }
};