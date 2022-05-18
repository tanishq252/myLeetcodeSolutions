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

    ListNode* middleElementOfList(ListNode *head){
        if(head == NULL) return NULL;
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = head;
        while(fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next =NULL;
        return slow;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return new TreeNode(head->val);
        
        ListNode *middleNode = middleElementOfList(head);
        TreeNode *root = new TreeNode(middleNode->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(middleNode->next);
        return root;
    }
};