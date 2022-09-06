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
    map<string, int> mp;
    set<TreeNode*> st;
    vector<TreeNode*> vec;
    string traverse(TreeNode *root){
        if(root == NULL) return "null";
        string v = to_string(root->val)+","+traverse(root->left)+","+traverse(root->right);
        if(mp[v]++==1){
            vec.push_back(root);
        }
        return v;
    }

    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        string s = traverse(root);
        // mp[s].push_back(root);
        // vector<TreeNode*> ans;
        // for(auto i:mp){
        //     if(i.second.size() >= 2){
        //         ans.push_back(i.second[0]);
        //     }
        // }
        return vec;
    }
};