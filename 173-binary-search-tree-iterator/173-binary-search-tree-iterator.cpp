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
class BSTIterator {
public:
    int i=0;
    vector<int> v;
    void inOrder(vector<int> &v, TreeNode* root){
        if(root==NULL){return;}
        inOrder(v, root->left);
        v.push_back(root->val);
        inOrder(v, root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inOrder(v, root);
    }
    
    int next() {
        if(i<v.size()){
            return v[i++];
        }
        return 0;
    }
    
    bool hasNext() {
        if(i>=v.size()){return false;}
        return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */