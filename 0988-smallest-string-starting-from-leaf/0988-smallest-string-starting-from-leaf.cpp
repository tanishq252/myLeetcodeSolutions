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
    priority_queue<string, vector<string>, greater<string>> pq;
    string alphs = "abcdefghijklmnopqrstuvwxyz";
    void dfs(TreeNode* root, string s){
        if(root==NULL) return;
        if(root->left==NULL and root->right==NULL){
            s = alphs[root->val]+s;
            pq.push(s);
            return;
        }
        // cout<<'a'+root->val<<" ";
        s = alphs[root->val]+s;
        dfs(root->left, s);        
        dfs(root->right, s);
    }
    string smallestFromLeaf(TreeNode* root) {
        string s="";
        dfs(root,s);
        return pq.top();
    }
};