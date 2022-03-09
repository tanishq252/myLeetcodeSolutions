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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){return head;}
        ListNode *temp = head;
        ListNode *dum = new ListNode();
        dum->next = head;
        while(temp){
            if(temp->next && temp->val == temp->next->val){
                while(temp->next && temp->val == temp->next->val){
                    temp = temp->next;
                }
                if(dum->next == head){
                    head = temp->next;
                }
                dum->next = temp->next;
            }else{
                dum = dum->next;
            }
            
            
            temp = temp->next;
        }
        return head;
    }
};