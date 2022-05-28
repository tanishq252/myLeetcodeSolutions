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
    int sum =0;
    void recur(TreeNode *root, bool grandParentEven){
        if(root==NULL) return;
        if(grandParentEven){
            sum+= (((root->left!=NULL) ? root->left->val:0)+((root->right!=NULL) ? root->right->val:0));
        }
        grandParentEven = (root->val%2==0) ? true:false;
        recur(root->left, grandParentEven);        
        recur(root->right, grandParentEven);
    }
    int sumEvenGrandparent(TreeNode* root) {
        recur(root, false);
        return sum;
    }
};