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
    void preOrder(TreeNode *root, vector<int> &v){
        if(root == NULL) return;
        v.push_back(root->val);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
    
    void insert(TreeNode *root, int val){
        while(root->right!=NULL){
            root = root->right;
        }
        root->right = new TreeNode(val);
    }
    
    void flatten(TreeNode* root) {
        vector<int> v;
        preOrder(root, v);
        if(root==NULL) return;
        root->left = NULL;        
        root->right = NULL;
        TreeNode *temp = root;
        for(int i=1;i<v.size();i++){
            TreeNode *newNode = new TreeNode(v[i]);
            temp->right = newNode;
            temp = temp->right;
        }
        
    }
};