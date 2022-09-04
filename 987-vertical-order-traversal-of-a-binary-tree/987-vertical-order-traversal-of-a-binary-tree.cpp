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
    map<int, vector<pair<int, int>>> mp;
    void preOrder(TreeNode *root, int ind, int lvl){
        if(root == NULL) return;
        mp[ind].push_back({lvl, root->val});
        preOrder(root->left, ind-1, lvl+1);        
        preOrder(root->right, ind+1, lvl +1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        preOrder(root, 0, 0);
        vector<vector<int>> ans;int k=0;
        for(auto i:mp){
            sort(i.second.begin(), i.second.end());
            ans.push_back({});
            for(auto j:i.second){
                ans[k].push_back(j.second);
            }
            k++;
        }
        return ans;
    }
};