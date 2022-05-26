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
    void insert(ListNode **head, int data){
        if((*head) == NULL) {(*head) = new ListNode(data);return;}
        ListNode *temp = *head;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = new ListNode(data);
    }
    ListNode* swapPairs(ListNode* head) {
        if(head ==NULL or head->next==NULL) return head;
        ListNode *temp = head;
        ListNode *headnew = NULL;
        while(temp->next!=NULL and temp!=NULL){
            insert(&headnew, temp->next->val);
            insert(&headnew, temp->val);
            if(temp->next->next!=NULL){
                if( temp->next->next->next ==NULL ){
                    insert(&headnew, temp->next->next->val);
                }
            }
            temp = temp->next->next;
            if(temp==NULL) break;
        }
        return head=headnew;
    }
};