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
    TreeNode* insert(int low, int high, vector<int> v){
        if(high<low) return NULL;
        int mid = (high+low)/2;
        TreeNode *root = new TreeNode(v[mid]);
        root->left = insert(low, mid-1, v);        
        root->right = insert(mid+1, high, v);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode *root = insert(0, nums.size()-1, nums);
        return root;
    }
};