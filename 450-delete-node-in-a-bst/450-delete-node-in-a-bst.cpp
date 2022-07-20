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
    TreeNode* minValueNode(TreeNode* root){
        TreeNode *current = root;
        while(current and current->left){
            current = current->left;
        }
        return current;
    }
    
    TreeNode* deleteNode(TreeNode* root, int val) {
        if(root ==  NULL) return NULL;
        if(val > root->val){
            root->right = deleteNode(root->right, val);
        }else if(val < root->val){
            root->left = deleteNode(root->left, val);
        }else{
            if(root->left == NULL and root->right==NULL){
                return NULL;
            }
            else if(root->left == NULL){
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }else if(root->right == NULL){
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            TreeNode *temp = minValueNode(root->right);
            root->val = temp->val;
            root->right = deleteNode(root->right, temp->val);
            
        }
        return root;
    }
};