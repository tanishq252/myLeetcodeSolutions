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
    int count = 0;
    void inOrder(TreeNode *root){
        if(root==NULL) return;
        inOrder(root->left);
        count++;
        inOrder(root->right);
    }
    int countNodes(TreeNode* root) {
        inOrder(root);
        return count;
    }
};