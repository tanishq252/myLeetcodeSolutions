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
    
    void recursionTraverse(TreeNode *root, int path[], int pathLen, vector<vector<int>> &ans, int targetSum){
        if(root==NULL){
            return;
        }
        path[pathLen] = root->val;
        pathLen++;
        
        if(root->left==NULL && root->right==NULL){
            vector<int> v;
            int s=0;
            for(int i=0;i<pathLen;i++){
                s+=path[i];
            }
            if(s==targetSum){
                for(int i=0;i<pathLen;i++){
                v.push_back(path[i]);
                }
                ans.push_back(v);
            }
        }
        else{
            recursionTraverse(root->left, path, pathLen, ans, targetSum);
            recursionTraverse(root->right, path, pathLen, ans, targetSum);

        }
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        int path[5000];
        recursionTraverse(root, path, 0, ans, targetSum);
        return ans;
    }
};