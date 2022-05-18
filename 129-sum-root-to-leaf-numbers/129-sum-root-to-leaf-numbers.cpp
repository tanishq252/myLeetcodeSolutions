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
    int finalAns =0;
    int mod = 1000000007;
    void calculate(int arr[], int n){
        long long int i=1;
        int ans=0;
        for(int j = n-1;j>=0;j--){
            ans+=(arr[j]*i);
            i= i*10;
        }
        finalAns+=ans;
    }
    void pathTraverse(TreeNode *root, int pathLen, int path[]){
        if(root==NULL){
            return;
        }
        path[pathLen] = root->val;
        pathLen++;
        
        if(root->left == NULL and root->right == NULL){
            calculate(path, pathLen);
        }else{
            pathTraverse(root->left, pathLen, path);             
            pathTraverse(root->right, pathLen, path); 
        }
    }
    int sumNumbers(TreeNode* root) {
        // we can have 1000 nodes max
        int path[1000];
        // int pathLen = 0;
        pathTraverse(root, 0, path);
        return finalAns;
        
    }
};