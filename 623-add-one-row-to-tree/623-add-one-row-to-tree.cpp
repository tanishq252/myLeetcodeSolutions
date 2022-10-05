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
    int d, vale;
    void recur(TreeNode *root, int depth){
        if(root == NULL ) return;
        if(depth == 1){
            TreeNode *newN = new TreeNode(vale);
            newN->left = root->left;
            root->left = newN;
            TreeNode *newn = new TreeNode(vale);
            newn->right = root->right;
            root->right = newn;
            return;
        }
        recur(root->left, depth-1);
        recur(root->right, depth-1);
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        d = depth;vale = val;
        if(depth == 1){
            TreeNode *newN = new TreeNode(vale);
            newN->left = root;
            return newN;
        }
        recur(root, depth-1);
        return root;
    }
};