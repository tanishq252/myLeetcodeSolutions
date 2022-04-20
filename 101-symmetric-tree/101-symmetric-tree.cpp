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
    void inOrder(vector<int> &v, TreeNode *root){
        if(root==NULL){
            v.push_back(-1001);
            return;}
                v.push_back(root->val);

        inOrder(v, root->left);
        inOrder(v, root->right);
    }
    
    void swap(TreeNode **n1, TreeNode **n2){
        TreeNode *t = *n1;
        *n1 = *n2;
        *n2 = t;
    }
    
    void invert(TreeNode *root){
        if(root==NULL){return;}
        invert(root->left);
        invert(root->right);
        swap(&(root->left), &(root->right));
    }

    void preOrderInvert(TreeNode *root){
        if(root==NULL){return;}
        preOrderInvert((root->left));
        preOrderInvert((root->right));
        swap(&(root->left), &(root->right));
    }
    
    TreeNode* invertTree(TreeNode* root) {
        vector<int> v,m;
        inOrder(v, root);
        for(auto i:v){cout<<i<<" ";}
        cout<<"\n";
        
        preOrderInvert(root);
        inOrder(m, root);
        for(auto i:m){cout<<i<<" ";}
        cout<<"\n";
        
        return root;
    }
    
    bool isSymmetric(TreeNode* root) {
        // invert(root->left);
        // return root->right==root->left;
        
        // inOrder(r, root);
        // for(auto i:r){cout<<i<<" ";}
        // cout<<"\n";
        vector<int> l,r;
        preOrderInvert(root->right);
        inOrder(l, root->right);
                for(auto i:l){cout<<i<<" ";}
        inOrder(r, root->left);
                for(auto i:r){cout<<i<<" ";}
        return r==l;

    }
};