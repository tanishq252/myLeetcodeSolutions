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
    int preOrderIndex = 0;
    map<int, int> inorderIndex;

    TreeNode* buildTree(vector<int>& preOrder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            inorderIndex[inorder[i]] = i;
        }
        return convertToTree(preOrder, 0, preOrder.size()-1);
    }
    
    TreeNode *convertToTree(vector<int> &preOrder, int left, int right){
        if(left>right) return NULL;
        int rootVal = preOrder[preOrderIndex++];
        TreeNode *root = new TreeNode(rootVal);
        
        root->left = convertToTree(preOrder, left, inorderIndex[rootVal]-1);                 root->right = convertToTree(preOrder, inorderIndex[rootVal]+1, right);
        return root;
    }
};