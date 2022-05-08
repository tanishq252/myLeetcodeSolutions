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
    
    void pathRecursion(TreeNode *root, int path[], int pathLen, vector<int> &v){
        if(root==NULL){
            return;
        }
        
        path[pathLen] = root->val;
        pathLen++;
        
        if(root->left == NULL && root->right==NULL){
            int s=0;
            for(int i=0;i<pathLen;i++){
                s+=path[i];
            }
            v.push_back(s);
        }else{
            pathRecursion(root->left, path, pathLen, v);            
            pathRecursion(root->right, path, pathLen, v);

        }
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        vector<int> v;
        int path[5000];

        pathRecursion(root, path, 0, v);
        
        for(auto i:v){
            if(i==targetSum){
                return true;
            }
        }
        
        return false;
    }
};