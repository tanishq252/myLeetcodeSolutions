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
    
    void recursionTraverse(TreeNode *root ,int path[], int pathLen, vector<string> &ans){
        if(root==NULL){return;}
        
        path[pathLen] = root->val;
        pathLen++;
        
        if(root->left==NULL && root->right==NULL){
            string s="";
            for(int i=0;i<pathLen-1;i++){
                s+= to_string(path[i]);
                s+= "->";
            }
            s+= to_string(path[pathLen-1]);
            ans.push_back(s);
        }
        else{
            recursionTraverse(root->left, path, pathLen, ans);
            recursionTraverse(root->right, path, pathLen, ans);

        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        int path[100];
        recursionTraverse(root, path, 0, ans);
        return ans;
    }
};