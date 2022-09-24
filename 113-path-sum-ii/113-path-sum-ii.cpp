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
    int target;
    void recur(TreeNode *root, int i, int path[]){
        if(root == NULL) return;
        path[i] = root->val;
        i++;
        if(root->left == NULL and root->right == NULL){
            int s=0;
            for(int j=0;j<i;j++){
                s+=path[j];
            }
            if(s == target){
               vector<int> v;
               for(int j=0;j<i;j++){
                    v.push_back(path[j]);
                }
                ans.push_back(v);
            }
        }else{
            recur(root->left, i, path);
            recur(root->right, i, path);
        }
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target = targetSum;
        int path[5000];
        recur(root, 0, path);
        return ans;
        
    }
};