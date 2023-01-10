// https://leetcode.com/problems/same-tree/description/


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
    vector<int> v1,v2;
    void preOrder(vector<int> &v, TreeNode *root){
        if(root == NULL) {
            v.push_back(-1);
            return;
        }
        v.push_back(root->val);
        preOrder(v, root->left);
        preOrder(v, root->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        preOrder(v1, p);
        preOrder(v2, q);
        for(auto &i:v1){
            cout<<i<<" ";
        }
        cout<<"\n";
        for(auto &i:v2){
            cout<<i<<" ";
        }
        return v1==v2;
    }
};