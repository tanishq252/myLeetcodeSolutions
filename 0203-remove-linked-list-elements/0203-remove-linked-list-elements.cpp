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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head == NULL) return NULL;
        while(head->val == val){
            head = head->next;
            if(head == NULL) return NULL;
        }
        ListNode *n=head->next;
        ListNode *p=head;
        if(n==NULL or p==NULL) return head;
        while(n){
            if(n->val == val){
                p->next = n->next;
                if(n->next==NULL) return head;
                n = n->next;
            }else{
                n = n->next;
                p = p->next;
            }
        }
        return head;
    }
};