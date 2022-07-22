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
    vector<int> mergeElements(vector<int> &elements1, vector<int> &elements2){
        if(elements1.size() == 0){
            return elements2;
        }
        if(elements2.size() == 0){
            return elements1;
        }
        int i=0, j=0, k=0;
        vector<int> mergedElements(elements1.size()+elements2.size(),0);
        while(i<elements1.size() and j<elements2.size()){
            if(elements1[i] > elements2[j]){
                mergedElements[k++] = elements2[j++];
            }else{
                mergedElements[k++] = elements1[i++];
            }
        }
        while(i<elements1.size()){
            mergedElements[k++] = elements1[i++];
        }
        while(j<elements2.size()){
            mergedElements[k++] = elements2[j++];
        }
        return mergedElements;
    }
    
    void inorder(TreeNode *root, vector<int> &elements){
        if(root == NULL) return;
        
        inorder(root->left, elements);
        elements.push_back(root->val);
        inorder(root->right, elements);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> elements1;        
        vector<int> elements2;
        inorder(root1, elements1);        
        inorder(root2, elements2);
        cout<<elements1.size();
        return mergeElements(elements1, elements2);
    }
};