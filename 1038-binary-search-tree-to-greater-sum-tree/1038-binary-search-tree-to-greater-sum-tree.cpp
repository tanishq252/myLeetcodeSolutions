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
    int greaterSum(TreeNode *root, int prevSum){
        if(root == NULL) return 0;
        int currentSum = root->val;
        currentSum+=greaterSum(root->right, 0+prevSum);
        root->val = currentSum+prevSum;
        currentSum+=greaterSum(root->left, currentSum+prevSum);
        return currentSum;
    }
    
    TreeNode* bstToGst(TreeNode* root) {
        //
        int findGreaterRight = greaterSum(root->right, 0);
        root->val += findGreaterRight;
        int findGreaterLeft = greaterSum(root->left, root->val);
        return root;
    }
};