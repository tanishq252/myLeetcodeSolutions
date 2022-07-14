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
    int postOrderInd =0;
    map<int, int> inorderindexes;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            inorderindexes[inorder[i]] = i;
        }
        
        // reversing postorder gives us parent-right-left
        reverse(postorder.begin(), postorder.end());
        return constructTree(postorder, 0, postorder.size()-1);
    }
    
    TreeNode *constructTree(vector<int> &postorder, int left, int right){
        if( left> right) return NULL;
        
        int currentRootVal = postorder[postOrderInd++];
        TreeNode *root = new TreeNode(currentRootVal);
        
        //as we have PRL we have to traverse the right subtree first then left
        root->right = constructTree(postorder, inorderindexes[currentRootVal]+1, right);
        root->left = constructTree(postorder, left, inorderindexes[currentRootVal]-1); 
        
        return root;
    }
};