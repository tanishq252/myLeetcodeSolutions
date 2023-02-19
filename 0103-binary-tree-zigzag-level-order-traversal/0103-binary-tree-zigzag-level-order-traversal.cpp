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
    vector<vector<int>> ans;
    int z=0;
    void zigzag(TreeNode* root, int level){
        if(root == NULL) return;
        if(ans.size() == level) ans.push_back({});
        ans[level].push_back(root->val);
        zigzag(root->left,level+1);        
        zigzag(root->right,level+1);

    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int eve=0;
        zigzag(root, 0);
        vector<vector<int>> a;
        for(auto i:ans){
            if(eve%2==1){
                reverse(i.begin(), i.end());
            }
            eve++;                
            a.push_back(i);
        }
        return a;
    }
};