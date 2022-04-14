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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){
            return NULL;
        }
        
        while(root->val!=val){
            if(root->val>val){
                root = searchBST(root->left, val);
                if(root==NULL){
                    return NULL;
                }
            }
            else if(root->val<val){
                root = searchBST(root->right, val);
                if(root==NULL){
                    return NULL;
                }
            }
        }
        
        return root;
        
    }
};