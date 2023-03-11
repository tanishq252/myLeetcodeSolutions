/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> v;

    void func(int l, int r, TreeNode **root){
        if(r>=l){
            int m = (l+r)/2;
            (*root) = new TreeNode(v[m]);
            func(l, m-1, &((*root)->left));
            func(m+1, r, &((*root)->right));
        }
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        TreeNode* root = NULL;
        ListNode* t=head;
        while(t!=NULL){
            v.push_back(t->val);
            t = t->next;
        }
        func(0, v.size()-1, &root);
        return root;
    }
};