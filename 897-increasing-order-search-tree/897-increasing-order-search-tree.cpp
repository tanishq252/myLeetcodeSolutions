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
    void inorder(vector<int> &v, TreeNode* root){
        if(root==NULL){
            return;
        }
        inorder(v, root->left);
        v.push_back(root->val);
        inorder(v, root->right);
        
    }
    
    TreeNode* formTree(vector<int> v){
        TreeNode *newTree = new TreeNode(v[0]);
        TreeNode *ptr = newTree;
        if(v.size()>1){
            for(int i=1;i<v.size();i++){
                TreeNode *newNode = new TreeNode(v[i]);
                ptr->right = newNode;
                ptr = ptr->right;
            }
        }
        else{
            return newTree;
        }
        return newTree;
    }
    
    TreeNode* increasingBST(TreeNode* root) {
        vector<int> v;
        inorder(v, root);
        TreeNode *newTree = formTree(v);
        return newTree;
        
    }
};