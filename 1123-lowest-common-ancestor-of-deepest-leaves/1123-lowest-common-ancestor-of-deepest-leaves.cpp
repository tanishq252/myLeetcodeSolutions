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
    vector<vector<TreeNode*>> v;
    TreeNode* ans=NULL;
    int deepest = 0;
    int levelOrder(TreeNode *root, int depth){
        deepest = max(deepest, depth);
        if(root == NULL){
            return depth;
        }
        int l = levelOrder(root->left, depth+1);
        int r = levelOrder(root->right, depth+1);
        if(l == deepest and r == deepest){
            ans = root;
        }
        return max(l,r);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        int d = levelOrder(root, 0);
        return ans;
    }
};