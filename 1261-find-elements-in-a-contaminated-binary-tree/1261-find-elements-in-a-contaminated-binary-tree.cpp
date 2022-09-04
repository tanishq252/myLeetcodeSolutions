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
class FindElements {
public:
    vector<int> v;
    
    // simple preorder traversal to keep on updating the values as per the given problem
    void preOrder(TreeNode *root, int val){
        if(root==NULL) return;
        // appending all the values so that later we can check whether the given value is present in these values or not
        v.push_back(val);
        preOrder(root->left, 2*val+1);        
        preOrder(root->right, 2*val+2);
    }
    
    FindElements(TreeNode* root) {
        preOrder(root, 0);
    }
    
    bool find(int target) {
        if(count(v.begin(), v.end(), target) == 0) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */