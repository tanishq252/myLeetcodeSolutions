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
        if(root==NULL){return;}
        inOrder(v, root->left);
        v.push_back(root->val);
        inOrder(v, root->right);
    }
    
    void update(vector<int> v,int &i, TreeNode *root){
        if(root==NULL){return;}
        update(v, i, root->left);
        root->val = (root->val!=v[i]) ? v[i]:root->val;
        i++;
        update(v, i, root->right);
    }
    
    void recoverTree(TreeNode* root) {
        vector<int> v;
        inOrder(v, root);
        for(auto i:v) cout<<i<<" ";
        int i=0;
        sort(v.begin(), v.end());
        update(v, i, root);
    }
};